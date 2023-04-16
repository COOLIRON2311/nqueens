#include <functional>
#include "Nqueens.h"

// ----------------------
// Change run params here
// ----------------------
#define N 8
#define F annealing

template<size_t dim>
void result(function<Grid<N>()> f)
{
    auto r = f();
    int queens = 0;
    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            if (r.get(i, j))
            {
                queens++;
                cout << "Q ";
            }
            else
                cout << ". ";
        }
        cout << endl;
    }
    cout << "Queens: " << queens << endl;
}


int main()
{
    result<N>(F<N>);
    return 0;
}
