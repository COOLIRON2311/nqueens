#pragma once
#include <iostream>
#include <algorithm>
#include <random>
#include <functional>
#include <vector>
#include <string>
#include <bitset>
#include <memory>
#include <queue>
#include <stack>
#include <array>

using namespace std;

#define TEMP 4000 // Temperature for simulated annealing
#define COOLING 0.99 // Cooling rate for simulated annealing

template <size_t N>
class Grid
{
    bitset<N * N> grid;

public:
    Grid() : grid(0) {}
    Grid(initializer_list<int> rows) : grid(0)
    {
        int i = 0;
        for (auto row : rows)
        {
            set(i, row, true);
            i++;
        }
    }
    Grid &operator=(const Grid &g)
    {
        grid = g.grid;
        return *this;
    }
    bool operator==(const Grid &g) const
    {
        return grid == g.grid;
    }
    inline bool get(int x, int y) const { return grid[y * N + x]; }
    inline void set(int x, int y, bool val)
    {
        // if (x >= 0 && x < N && y >= 0 && y < N)
        grid[y * N + x] = val;
    }
    bool is_valid() const
    {
        vector<pair<uint16_t, uint16_t>> queens;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (get(i, j))
                    queens.push_back(make_pair(i, j));
            }
            for (int q1 = 1; q1 < queens.size(); q1++)
            {
                for (int q2 = 0; q2 < q1; q2++)
                {
                    if (queens[q1].first == queens[q2].first ||
                        queens[q1].second == queens[q2].second ||
                        abs(queens[q1].first - queens[q2].first) == abs(queens[q1].second - queens[q2].second))
                        return false;
                }
            }
        }
        return true;
    }

    inline bool not_null() const
    {
        return grid != 0;
    }

    int queens() const
    {
        int count = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (get(i, j))
                    count++;
            }
        }
        return count;
    }

    friend ostream &operator<<(ostream &os, const Grid<N> &g)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                os << g.get(j, i) << " ";
            }
            os << endl;
        }
        return os;
    }
    void reset() { grid.reset(); }
};

template <size_t N>
class State
{
public:
    Grid<N> g;
    int queens;
    State() : g(), queens(0) {}
    State(const Grid<N> &g, int queens) : g(g), queens(queens) {}
};

template <size_t N>
Grid<N> bfs()
{
    using StatePtr = shared_ptr<State<N>>;
    queue<StatePtr> q;
    StatePtr s = make_shared<State<N>>(Grid<N>{}, 0);
    q.push(s);
    while (!q.empty())
    {
        StatePtr s = q.front();
        q.pop();

        if (!s->g.is_valid())
        {
            continue;
        }

        else if (s->queens == N)
            return s->g;

        for (int i = 0; i < N; i++)
        {
            StatePtr s2 = make_shared<State<N>>(s->g, s->queens);
            s2->g.set(s2->queens++, i, true);
            q.push(s2);
        }
    }
    return s->g;
}

template <size_t N>
Grid<N> dfs()
{
    using StatePtr = shared_ptr<State<N>>;
    stack<StatePtr> q;
    StatePtr s = make_shared<State<N>>(Grid<N>{}, 0);
    q.push(s);
    while (!q.empty())
    {
        StatePtr s = q.top();
        q.pop();

        if (!s->g.is_valid())
            continue;

        else if (s->queens == N)
            return s->g;

        for (int i = 0; i < N; i++)
        {
            StatePtr s2 = make_shared<State<N>>(s->g, s->queens);
            s2->g.set(s2->queens++, i, true);
            q.push(s2);
        }
    }
    return s->g;
}

template <size_t N>
Grid<N> _ids(int bound)
{
    using StatePtr = shared_ptr<State<N>>;
    stack<StatePtr> q;
    StatePtr s = make_shared<State<N>>(Grid<N>{}, 0);
    q.push(s);
    while (!q.empty())
    {
        StatePtr s = q.top();
        q.pop();

        if (!s->g.is_valid())
            continue;

        else if (s->queens == N)
            return s->g;

        else if (s->queens == bound)
            continue;

        if (s->queens < bound)
        {
            for (int i = 0; i < N; i++)
            {
                StatePtr s2 = make_shared<State<N>>(s->g, s->queens);
                s2->g.set(s2->queens++, i, true);
                q.push(s2);
            }
        }
    }
    return s->g;
}

template <size_t N>
Grid<N> ids()
{
    for (int i = 0; i <= N; i++)
    {
        Grid<N> g = _ids<N>(i);
        if (g.not_null())
            return g;
    }
    return Grid<N>{};
}

template <size_t N>
int fitness(const array<int, N> &a)
{
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (a[i] == a[j] || abs(a[i] - a[j]) == abs(i - j))
                count++;
        }
    }
    return count;
}

template <size_t N>
void mutate(array<int, N> &a)
{
    int i = rand() % N;
    int old = a[i];
    do
    {
        a[i] = rand() % N;
    } while (a[i] == old);
}

template <size_t N>
void crossover(array<int, N> &a, array<int, N> &b)
{
    int i = a.size() / 2;
    for (; i < a.size(); i++)
    {
        swap(a[i], b[i]);
    }
}

template <size_t N>
Grid<N> arrtogrid(const array<int, N> &a)
{
    Grid<N> g;
    for (int i = 0; i < N; i++)
        g.set(i, a[i], true);
    return g;
}

template <size_t N>
Grid<N> genetic(int p = 1000, double m = 0.1, int g = 10000)
{
    srand(time(0));
    using State = array<int, N>;
    vector<State> population;
    for (int i = 0; i < p; i++)
    {
        array<int, N> a;
        for (int j = 0; j < N; j++)
        {
            a[j] = rand() % N;
        }
        population.push_back(a);
    }
    for (int i = 0; i < g; i++)
    {
        sort(population.begin(), population.end(), [](const State &a, const State &b)
             { return fitness(a) < fitness(b); });

        if (fitness(population[0]) == 0)
           return arrtogrid(population[0]);

        for (int j = p / 2; j < p; j++)
        {
            if (rand() % 100 < m * 100)
                mutate(population[j]);
            else
                crossover(population[j], population[rand() % (p / 2)]);
        }
    }
    return Grid<N>{};
}

template <size_t N>
Grid<N> annealing()
{
    srand(time(0));
    array<int, N> answer;
    for (int i = 0; i < N; i++)
        answer[i] = i;

    shuffle(answer.begin(), answer.end(), default_random_engine(time(0)));
    int f = fitness(answer);

    array<int, N> current;
    double t = TEMP;
    while (t > 0)
    {
        int rc1 = rand() % N; // random column 1
        int rc2 = rand() % N; // random column 2
        t *= COOLING;

        current = answer;
        while (current[rc1] == current[rc2])
        {
            rc1 = rand() % N;
            rc2 = rand() % N;
        }
        swap(current[rc1], current[rc2]); // swap two random queens
        double delta = fitness(current) - f; // calculate delta
        if (delta < 0)
        {
            answer = current;
            f = fitness(answer);
        }
        else if (exp(-delta / t) > (rand() % 100) / 100.0) // accept worse solution
        {
            answer = current;
            f = fitness(answer);
        }
        if (f == 0) // if solution is found
            return arrtogrid(answer);
    }
    return Grid<N>{};
}
