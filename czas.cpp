#include<iostream>
#include<cstdlib>
#include<cmath>

struct czas {
    short int godziny;
    short int minuty;
    short int sekundy;
};

void odejmij_godzine(czas s1, czas s2, czas s3) {
	s3.sekundy = s1.sekundy - s2.sekundy;
	s3.minuty = s1.minuty - s2.minuty;
    s3.godziny = s1.godziny - s2.godziny;

    if(s3.sekundy < 0){
    	s3.minuty -= 1;
    	s3.sekundy += 60;
    }

    if(s3.minuty < 0){
    	s3.godziny -= 1;
    	s3.minuty += 60;
    }

    if(s3.godziny < 0){
        s3.godziny += 24;
    }

    std::cout<<s3.godziny<<":"<<s3.minuty<<"."<<s3.sekundy<<std::endl;
}




void dodaj_godzine(czas s1, czas s2, czas s3) {
	s3.sekundy = s1.sekundy + s2.sekundy;
	s3.minuty = s1.minuty + s2.minuty;
    s3.godziny = s1.godziny + s2.godziny;


    if(s3.sekundy >= 60){
    	int plus_min = std::floor(s3.sekundy/60);
    	s3.sekundy -= plus_min * 60;
    	s3.minuty += plus_min;
    }

    if(s3.minuty >= 60){
    	int plus_godz = std::floor(s3.minuty/60);
    	s3.minuty -= plus_godz * 60;
    	s3.godziny += plus_godz;
    }

    if(s3.godziny >= 24){
        s3.godziny -= 24;
    }

    std::cout<<s3.godziny<<":"<<s3.minuty<<"."<<s3.sekundy<<std::endl;
}

int main(){

    czas T1 = {22,30,40};
    czas T2 = {2,30,21};
    czas T3 = {0,0,0};
    czas T4 = {0,0,0};

	odejmij_godzine(T2, T1, T3);
	dodaj_godzine(T2, T1, T4);

	return 0;
}
