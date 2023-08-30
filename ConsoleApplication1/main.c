#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//#include <unistd.h>
#include "gpssim.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char* argv[]) {

	printf("Hello\n");
	//char* param = "-e brdc0010.22n -u circle.csv -o gps_bin_ -s 1000000 -d 10";
	//char* param = "-e brdc0010.22n -l 30.286502,120.032669,100 -d 10 -o gps_bin_ -s 1000000";
	//char* param = "-e brdc0010.22n -u circle_llh.csv -d 10 -o gps_bin_ -s 1000000";
	//char* param = "-l 36.318462,138.996902,100 -s 1000000 -T 2023/07/24,20:48:00.6";
	char* param = "-l 36.318462,138.996902,100 -s 1000000";
	//char* base_path = "C:\\Users\\duyga\\OneDrive\\デスクトップ\\WORKS\\Nissan GPS\\Debug\\ConsoleApplication1";
	int res = 0;
	short res1[200000];

	char* rinex_file = "C:\\Users\\duyga\\OneDrive\\デスクトップ\\WORKS\\Nissan GPS\\Debug\\ConsoleApplication1\\brdc0010.22n";

	int neph = read_RINEX_file(rinex_file);
	int set = settings(param);

	//double coord[][3] = {
	//	{35.274015965, 137.014864092, 99.999},
	//	{35.274023485, 137.014864053, 99.999},
	//	{35.274030991, 137.014863935, 99.999},
	//	{35.274038502, 137.014863748, 99.998},
	//	{35.274046007, 137.014863483, 99.999},
	//	{35.274053514, 137.014863140, 99.999}
	//};

	char* pos_arr[] = {
		"35.274015965, 137.014864092,99.999",
		"35.274023485, 137.014864053,99.999",
		"35.274030991, 137.014863935,99.999",
		"35.274038502, 137.014863748,99.998",
		"35.274046007, 137.014863483,99.999",
		"35.274053514, 137.014863140,99.999"
	};

	char* pos_nmea[] = {
		"$GPGGA,000000.00,4852.46626694,N,00217.58140440,E,1,05,2.87,+0.00,M,-21.3213,M,,*5E",
		"$GPGGA,000000.10,4852.46626694,N,00217.58140440,E,1,05,2.87,+0.00,M,-21.3213,M,,*5F",
		"$GPGGA,000000.20,4852.46626694,N,00217.58140440,E,1,05,2.87,+0.00,M,-21.3213,M,,* 5C",
		"$GPGGA,000000.30,4852.46626694,N,00217.58140440,E,1,05,2.87,+0.00,M,-21.3213,M,,* 5D",
		"$GPGGA,000000.40,4852.46626694,N,00217.58140440,E,1,05,2.87,+0.00,M,-21.3213,M,,* 5A",
		"$GPGGA,000000.50,4852.46626694,N,00217.58140440,E,1,05,2.87,+0.00,M,-21.3213,M,,* 5B"
	};

	if (neph == 0 && set == 0) {
		for (int i = 0; i < 5; i++) {
			res = generate_100ms_IQ(res1);
			//set_position(pos_arr[i]);
			set_position_nmea(pos_nmea[i]);

			for (int i = 0; i < 30; i++) {
				fprintf(stderr, "data : %d\n", res1[i]);
			}

			//sleep(3);
		}
	}


	//double llh[] = { 30.286502, 120.032669, 100 };
	////fprintf(stderr, "data : %lf\n", llh[1]);
	//double xyz[3];
	//llh2xyz(llh, xyz);

	//fprintf(stderr, "x = %lf, y = %lf, z = %lf", xyz[0], xyz[1], xyz[2]);


	return res;
}