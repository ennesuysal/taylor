#include <stdio.h>
#include <math.h>

double turev(double x, int n)
{

	if(n==0) return sqrt(x);

	double carpim = 1.0;

	for(int i = 1; i<n; i+=1)
		{
			carpim = carpim*(2*i-1);		
		}
	
	return pow(-1, n+1)*(carpim/pow(2, n))*sqrt(pow(x, -2*n+1));
}

int fakt(int sayi){
	int c = 1;
	for(int i = 1; i<=sayi; i++)
	{
		c = c*i;
	}
	return c;
}	

double dn(int n, double h, double x0)
{

	double a;
	if(turev(x0, n)>turev(x0+h, n))
	{
		a=turev(x0, n);
	}

	else {
		a=turev(x0+h, n);
	}


	return fabs((pow(h, n)/fakt(n))*a);
}

int n_bulma(double hata, double h, double x0)
{
	int n = 1;
	while(1)
	{
		if(hata>=dn(n, h, x0)){
			return n;
		}

		n++;
	}
}

int tamkare(int sayi){

	for(int i = 1; i<=sayi; i++)
	{
		if(i*i==sayi)
		{
			return 1;
		}

	}

	return 0;
}

int hBul(int deger){

	int i=1;

	while(1)
	{

		if(tamkare(deger+i)==1)
			return -i;

		if(tamkare(deger-i)==1)
			return i;

		i++;

	}

	return 0;
}


double taylor(double hata, double deger)
{
	
	int h = hBul(deger);
	int x0 = deger-h;
	int n = n_bulma(hata, h, x0);


	printf("n = %d\n", n);
	printf("x0 = %d\n", x0);
	printf("h = %d\n", h);


	double sonuc=0;

	for(int k=0; k<n; k++)
	{
		sonuc = sonuc + (pow(h, k)/fakt(k))*turev(x0, k);
	}

	return sonuc;

}


int main(int argc, char const *argv[])
{
	int sayi;
	printf("==========\n");
	printf("TAYLOR FORMULU ILE KAREKOK HESABI\n");
	printf("==========\n\nKarekoku alinacak sayiyi girin: ");
	scanf("%d", &sayi);
	double hata;
	printf("Hata payini girin: ");
	scanf("%lf", &hata);

	double sonuc = taylor(hata, sayi);
	printf("Sonuc: %lf\nHata: %lf\n\n==========\n", sonuc, sqrt(sayi)-sonuc);
	return 0;
}
