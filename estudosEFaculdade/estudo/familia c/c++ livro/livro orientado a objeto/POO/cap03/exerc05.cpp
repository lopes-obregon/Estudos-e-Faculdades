#include <iostream>
using namespace std;
// programa que gera saidas com decremento e incremento
int main(int argc, char const *argv[])
{
	int aux, maior,menor,maiora,maiorb,maiorc,maiord,menora,menorb,menorc,menord;
	for (int i = 0; i < 2012; ++i)
	{
		if ((i == 2008) or (i == 2009) or (i == 2010) or (i == 2011))
		{
			maior = i;
			if (maior == 2008)
			{
				maiora = maior;
			}else{
				if (maior == 2009)
				{
					maiorb = maior;
				}else{
					if (maior == 2010){
						maiorc = maior;
					}else{
						if (maior == 2011)
						{
							maiord = maior;
						}
					}
				}
			}		

		}else{
			if ((i == 100) or (i == 400) or (i == 700) or (i == 1000))
			{	
				menor = i;
				if (menor == 100)
				{
					menora = menor;
				}else{
					if (menor == 400)
					{
						menorb = menor;
					}else{
						if (menor ==700){
							menorc = menor;
						}else{
							if (menor == 1000)
							{
								menord = menor;
							}
						}
					}
				}
			}
		}
	}
	cout << maiora << "\t" << menora << endl << maiorb << "\t" << menorb << endl << maiorc << "\t" << menorc << endl << maiord << "\t" << menord << endl;
	return 0;
}