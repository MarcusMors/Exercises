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
*/

void printMx3(long long arr[][3])
{
	long long length = sizeof(arr);
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			std::cout << arr[i] << "\t";
		}
		std::cout << "\n";
	}
	std::cout << "\n";
}

void printMx2(long long arr[][2])
{
	long long length = sizeof(arr);
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			std::cout << arr[i] << "\t";
		}
		std::cout << "\n";
	}
	std::cout << "\n";
}
void printArr(long long arr[])
{
	long long length = sizeof(arr);
	for (int i = 0; i < length; i++)
	{
		std::cout << arr[i] << "\t";
	}
	std::cout << "\n";
}

long long abs(long long num)
{
	return (num < 0) ? num * -1 : num;
}
bool reachable(long long pos1[2], long long pos2[2]) //angle of 45°
{
	return ((pos1[0] <= pos2[0]) && (pos1[1] <= pos2[1])) ? true : false;
}

long long max(long long arr[])
{
	long long length = sizeof(arr);
	long long max = 0;
	for (long long i = 0; i < length; i++)
	{
		max = (max < arr[i]) ? arr[i] : max;
	}
	return max;
}

long long walter(long long start[2], long long bearingsPoints[][3] = {0}, long long accumulated = 0)
{
	printArr(start);
	printMx3(bearingsPoints);
	long long length = sizeof(bearingsPoints);
	if (sizeof(bearingsPoints) == 1)
	{
		if (bearingsPoints[0][0] == 0)
		{
			cout << accumulated;
			return accumulated;
		}
		cout << accumulated;
		return accumulated;
	}
	// if sizeof(bearingPoints) == 1 return accumulated + bearingsPoints[0][3];
	// else
	accumulated += bearingsPoints[0][3];

	long long arr[length];

	long long auxStart[2];
	long long auxEnd[2];
	long long counter;

	for (long long i = 0; i < length; i++)
	{
		long long auxLength = (length - i) - 1;
		long long auxBearingsPoints[auxLength][3];

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
					auxBearingsPoints[counter][3] = bearingsPoints[j][3];
					counter++;
				}
			}
		}
		arr[i] = walter(auxStart, auxBearingsPoints, accumulated);
	}
	printArr(arr);
	return max(arr);
}

int main()
{
	long long n;
	cin >> n;
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
			std::cout << "continue ";
			printArr(auxBearingsPoints);
			continue;
		}
		bearingsPoints[count][0] = auxBearingsPoints[0];
		bearingsPoints[count][1] = auxBearingsPoints[1];
		bearingsPoints[count][2] = auxBearingsPoints[2];
		count++;
	}

	maxPoints = walter(start, bearingsPoints);
	std::cout << maxPoints << std::endl;
	return 0;
}
