
/////////////////////////////////////////////////////////////////////////////////
////В5  Задана матрица размером NxM.Определить количество различных элементов////
////матрицы(т.е повторяющиеся элементы считать один раз)                     ////
/////////////////////////////////////////////////////////////////////////////////
#include <iostream>	
using namespace std;

int main()
{
	 int N=0,M=0;
	 //Размер матрицы
	 {	
		 cout << "Please enter the number of rows in the matrix: ";
		 while (!(0 < N))
		 {
			 cin >> N;
			 if (!(0 < N))
			 {
				 cout << "Plese enter number of rows (0<N): ";
			 }
		 }
		 cout << "Please enter the number of columns in the matrix: ";
		 while (!(0 < M))
		 {
			 cin >> M;
			 if (!(0 < M))
			 {
				 cout << "Plese enter number of columns (0<M): ";
			 }
		 }
		 cout << "Marix size(" << N << "," << M << "):\n";
	 }	

	int **arr = new int*[N];
	for (int i = 0; i < N; i++)
	{
		arr[i] = new int[M];
	}

	//Ввод матрицы
	{
		cout << "Please enter number of array\n";

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				cout << "arr[" << i << "]" << "[" << j << "]= ";
				cin >> arr[i][j];
			}
		}
		cout << "Your array(" << N << "," << M << "):\n";
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				cout << arr[i][j] << " ";

			}
			cout << endl;
		}
	}

	
	
	
	//ALGORITM
	int count = N*M;
	int k=0, g=0;
	bool flag = false;
	for (int  i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{ 
			if (j==(N-1))
			{
				k = i + 1;
				g = 0;
			}
			else 
			{
				g = j + 1;	
				k = i;
			}
			   for (; k <N; k++)
			{
                for (;  g< M; g++)
				{
					//cout << i << " " << j << " " << k << " " << g << endl;
					if (arr[i][j]==arr[k][g])
					{
						
						count--;
						flag = true;
						break;
					}
				}
				g = 0;
				if (flag)
			   {
				   flag = false;
				   break;
			   }
			}
			   
			
        }
	}
		
	cout << "the number of different elements is equal to "<< count << endl;
		

	for (int i = 0; i < N; i++)
	{
		delete[] arr[i];

	}
	delete[] arr;
	system("pause");
	return 0;
}