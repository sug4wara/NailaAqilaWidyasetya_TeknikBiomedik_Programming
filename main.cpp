// NAMA		: Naila Aqila Widyasetya
// NRP		: 5023221012
// Jurusan	: Teknik Biomedik

#include <iostream>
#include <cmath>

#define GRAVITASI 10 //10 m/s^2
#define START_PENGUKURAN 1 //pengukuran dimulai dari 1 meter
#define SUDUT 45 //sudut elevasi tembakan

int mencari_V0(int a)
{
	int V0;
    if (a >= 1 && a<=10) V0 = a - 1;
    else if (a >= 11 && a<=20) V0 = a - 3;
    else if (a >= 21 && a<=30) V0 = a - 5;
  	return V0;
}

int jarak_total(int a, int b)
{
    int ab;
    ab = (pow(a,2)*sin(2*b*3.14159/180))/10;
    return ab;
}

double speed_dgn_loss(int a, int b)
{
	double v0loss;
    double Vtam;
    if (b >= 1 && b<=10) Vtam = 1;
    else if (b >= 11 && b<=20) Vtam = 3;
    else if (b >= 21 && b<=30) Vtam = 5;
    v0loss = sqrt((a * 10)/sin(2*SUDUT*3.14159/180)) + Vtam;
    return v0loss;
}

int main() {
    int Vt, V0, jarak;
    double nilaivt;

    std::cin >> Vt;
    V0 = mencari_V0(Vt);
    jarak = jarak_total(V0,SUDUT);
    nilaivt = speed_dgn_loss(jarak, Vt);

    std::cout << jarak << " " << nilaivt<< std::endl;
    return 0;
}
