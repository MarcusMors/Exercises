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

int abs(int num)
{
	return (num < 0) ? num * -1 : num;
}

long long max(long long arr[])
{
	long long length = sizeof(arr);
	long long max = 0;
	for (long long i = 0; i < length; i++)
	{
		if (max < arr[i])
		{
			max = arr[i];
		}
	}
	return max;
}

bool reachable(long long pos1[2], long long pos2[2]) //angle of 45°
{
	if (pos1[0] < pos2[0])
	{
	}
}

long long walter(long long start[2], long long bearingsPoints[][3], long long accumulated = 0)
{
	// if sizeof(bearingPoints) == 1 return accumulated + bearingsPoints[0][3];
	// else
	accumulated += bearingsPoints[0][3];

	long long length = sizeof(bearingsPoints);
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

		for (int j = 0; j < auxLength; j++)
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
	return max(arr);
}

long long main()
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
			continue;
		}
		bearingsPoints[count][0] = auxBearingsPoints[0];
		bearingsPoints[count][1] = auxBearingsPoints[1];
		bearingsPoints[count][2] = auxBearingsPoints[2];
		count++;
	}
	maxPoints = walter(start, bearingsPoints);
	cout << maxPoints << endl;
	return 0;
}
