#include<iostream>
#include<cstdio>
#include<fstream>

using namespace std;

int main(int argc, char **argv)
{
    void lu(float[][10], float[][10], float[][10], int n);
    void output(float[][10], int);
    float a[10][10], l[10][10], u[10][10];
    int n = 0, i = 0, j = 0;
    int b[n];
    cout << "Enter size of 2d array(Square matrix) : ";
    cin >> n;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cout << "Enter values no:" << i << ", " << j << ": ";
            cin >> a[i][j];
        }
    }
    cout << "Enter matrix b:";
    for (int k = 0; k < n; ++k) {
        cin >> b[k];
    }

    /*ifstream file;
    file.open("input.txt");
    file >> n;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++) {
            file >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        file >> b[i];
    }
    file.close();
    */

         lu(a, l, u, n);
    cout << "\nL Decomposition\n\n";
    output(l, n);
    cout << "\nU Decomposition\n\n";
    output(u, n);

    float y[n];
    y[0] = b[0]/l[0][0];
    for(int i=1; i < n; i++){
        float sum = 0;
        for (int k = 0; k < i; k++) {
            sum += l[i][k]*y[k];
        }

        y[i] = (b[i]-sum)/l[i][i];
    }

    for (int i1 = 0; i1 < n; ++i1) {
        printf("y[%d] =   %f \n", i1, y[i1]);
    }

    float x[n];
    for(int i=n-1; i>-1; i--){
        float sum = 0;
        for (int k=i+1; k < n; k++){
            sum += u[i][k]*x[k];
        }
        x[i] = y[i] - sum;
    }
    x[n-1] = y[n-1];
    cout << "    Results:" << endl;
    for (int m = 0; m < n; ++m) {
        //cout << "X[" << m+1 << "] = " << x[m] << endl;
        printf("X1[%d] = %f\n", m, x[m]);
    }

    return 0;
}
void lu(float a[][10], float l[][10], float u[][10], int n)
{
    int i = 0, j = 0, k = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (j < i)
                l[j][i] = 0;
            else
            {
                l[j][i] = a[j][i];
                for (k = 0; k < i; k++)
                {
                    l[j][i] = l[j][i] - l[j][k] * u[k][i];
                }
            }
        }
        for (j = 0; j < n; j++)
        {
            if (j < i)
                u[i][j] = 0;
            else if (j == i)
                u[i][j] = 1;
            else
            {
                u[i][j] = a[i][j] / l[i][i];
                for (k = 0; k < i; k++)
                {
                    u[i][j] = u[i][j] - ((l[i][k] * u[k][j]) / l[i][i]);
                }
            }
        }
    }
}
void output(float x[][10], int n)
{
    int i = 0, j = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%f ", x[i][j]);
        }
        cout << "\n";
    }
}
