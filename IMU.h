#include <Arduino.h>
          
void setup_IMU();

// moyenne normalisée de l'echantillon
float getCompassHeadingSample(int nb_sample, float exclusionPercentage);
/*/
float getCompassHeadingSample(int nb_sample);
/*/
int compare(const void *a, const void *b);

void getHeading(void);
void getTiltHeading(void);


void Mxyz_init_calibrated();

void get_calibration_Data();

void get_one_sample_date_mxyz();

void getAccel_Data(void);

void getGyro_Data(void);

void getCompass_Data(void);
void getCompassDate_calibrated();