#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <array>
#include <stack>

using namespace std;

/*** Chilling with Walter --- OmegaUP
 * https://omegaup.com/arena/CEP_2018/#problems/Chiliando-con-Walter
 * What is the MAXIMUM score can be reached?
 * can't reach a point over 45°
 */

/* Tests
Input
2
1 2 5
4 3 3
Output
3
input
3
5 5 8
6 1 5
8 0 4
Output
9
*/
int pass;

void printMx3(long long arr[][3], long long length)
{
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			std::cout << arr[i][j] << "\t";
		}
		std::cout << "\n";
	}
}

void printMx2(long long arr[][2], long long length)
{
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			std::cout << arr[i] << "\t";
		}
		std::cout << "\n";
	}
}
void printArr(long long arr[], int length)
{
	for (int i = 0; i < length; i++)
	{
		std::cout << arr[i] << "\t";
	}
	std::cout << std::endl;
}

// long long abs(long long num)
// {
// 	return (num < 0) ? (num * -1) : num;
// }

bool reachable(long long start[2], long long end[2]) //angle of 45°
{
	// long long x = end[0] - start[0];
	// long long y = abs((end[1] - start[1]));
	// cout << "\nstart\t: ";
	// printArr(start, 2);
	// cout << "end\t: ";
	// printArr(end, 2);
	// cout << "x , y \t: " << x << "\t" << y << endl;

	// if (x >= 0)
	// {
	// 	cout << x << " >= 0" << endl;
	// 	if (x >= y)
	// 	{
	// 		cout << x << " >= " << y << endl;
	// 		return true;
	// 	}
	// 	cout << x << " <= " << y << endl;
	// }
	// return false;
	return ((x >= 0) && (x >= y)) ? true : false;
}

long long max(long long arr[], long long length)
{
	long long max = 0;
	for (long long i = 0; i < length; i++)
	{
		max = (max < arr[i]) ? arr[i] : max;
	}
	return max;
}

long long walter(long long start[2], long long bearingsPoints[][3] = {0}, long long length = 0, long long accumulated = 0)
{
	cout << "Waldo" << endl;
	printArr(start, 2);
	cout << "length\t: " << length << endl;
	cout << "accumulated\t: " << accumulated << endl;
	printMx3(bearingsPoints, length);

	if (length == 0)
	{
		cout << "cero exit\t: " << accumulated << endl;
		return accumulated;
	}
	else if (length == 1)
	{
		cout << "else exit\t: " << accumulated + bearingsPoints[0][2] << endl;
		return accumulated + bearingsPoints[0][2];
	}

	long long arr[length];
	long long auxStart[2];
	long long auxEnd[2];
	long long counter;

	for (long long i = 0; i < length; i++)
	{
		long long auxLength = (length);
		long long auxBearingsPoints[auxLength][3];
		cout << "\n\t auxLength = " << auxLength << endl;

		counter = 0;
		auxStart[0] = bearingsPoints[i][0];
		auxStart[1] = bearingsPoints[i][1];

		for (long long j = 0; j < auxLength; j++)
		{
			if (j != i) // start != end
			{
				auxEnd[0] = bearingsPoints[j][0];
				auxEnd[1] = bearingsPoints[j][1];

				if (reachable(auxStart, auxEnd))
				{
					cout << "IS REACHABLE\t: " << counter << endl;
					printArr(auxStart, 2);
					printArr(auxEnd, 2);
					auxBearingsPoints[counter][2] = bearingsPoints[j][2];
					counter++;
				}
			}
		}
		cin >> pass;
		cout << accumulated << "\n\n";
		arr[i] = walter(auxStart, auxBearingsPoints, counter, accumulated + bearingsPoints[i][2]);
		cout << "arr[" << i << "]\t= " << arr[i] << endl;
	}
	cout << "arr:" << endl;
	printArr(arr, counter);
	cin >> pass;
	// return max(arr, counter);
	return accumulated;
}

int main()
{
	long long n;
	cin >> n;
	long long example[1];
	long long bearingsPoints[n][3];
	long long auxBearingsPoints[3];
	long long start[2] = {0, 0};
	long long maxPoints;
	long long count = 0;

	for (long long i = 0; i < n; i++)
	{
		// x , y , p
		cin >> auxBearingsPoints[0] >> auxBearingsPoints[1] >> auxBearingsPoints[2];
		// filter points
		if (auxBearingsPoints[1] > auxBearingsPoints[0]) //y > x = imposible
		{
			std::cout << "continue\n";
			continue;
		}
		bearingsPoints[count][0] = auxBearingsPoints[0];
		bearingsPoints[count][1] = auxBearingsPoints[1];
		bearingsPoints[count][2] = auxBearingsPoints[2];
		count++;
	}

	printArr(start, 2);
	cout << "length\t: " << count << endl;
	printMx3(bearingsPoints, count);
	cout << "SENT\n\n";

	maxPoints = walter(start, bearingsPoints, count, 0);
	std::cout << "MAX\t: " << maxPoints << std::endl;
	return 0;
}
