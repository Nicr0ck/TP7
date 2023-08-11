#define A 4
#define B 5
#define C 6
#define D 7 
#define E 8
#define F 9
#define G 10

#define s1  2
#define s2  3
#define s3  11
#define s4  12

			  // 0   1   2   3   4   5   6    7
int pines[]   = {A , B , C , D , E , F , G , s1 , s2 , s3 , s4 };
int estado[]  = {1 , 1 , 1 , 1 , 1 , 1 , 1 ,  0 ,  0 ,  0 ,  0 };
//  1 -> output    0 -> input
int binario[4];


//	pines[]	      A   B   C   D   E   F   G
int numCERO[]  = {1 , 1 , 1 , 1 , 1 , 0 , 1 };
int numUNO[]   = {0 , 1 , 1 , 0 , 0 , 0 , 0 };
int numDOS[]   = {1 , 1 , 0 , 1 , 1 , 1 , 0 };
int numTRES[]  = {1 , 1 , 1 , 1 , 0 , 1 , 0 };
int numCUATRO[]= {0 , 1 , 1 , 0 , 0 , 1 , 1 };
int numCINCO[] = {1 , 0 , 1 , 1 , 0 , 1 , 1 };
int numSEIS[]  = {1 , 0 , 1 , 1 , 1 , 1 , 1 };
int numSIETE[] = {1 , 1 , 1 , 0 , 0 , 0 , 0 };
int numOCHO[]  = {1 , 1 , 1 , 1 , 1 , 1 , 1 };
int numNUEVE[] = {1 , 1 , 1 , 0 , 0 , 1 , 1 };
int numA[]     = {1 , 1 , 1 , 0 , 1 , 1 , 1 };
int numB[]     = {0 , 0 , 1 , 1 , 1 , 1 , 1 };
int numC[]     = {1 , 0 , 0 , 1 , 1 , 0 , 1 };
int numD[]     = {0 , 1 , 1 , 1 , 1 , 1 , 0 };
int numE[]     = {1 , 0 , 0 , 1 , 1 , 1 , 1 };
int numF[]     = {1 , 0 , 0 , 0 , 1 , 1 , 1 };

//int* numeros[] = {numUNO,numSIETE,numOCHO,numNUEVE};
int* numeros[] = {numCERO,numUNO,numDOS,numTRES,numCUATRO,numCINCO,numSEIS,numSIETE,numOCHO,numNUEVE,numA,numB,numC,numD,numE,numF};


void setup()
{
  	for( int i=0 ; i < (sizeof(pines)/sizeof(int)) ; i++ )
    {
  		pinMode( pines[i] , estado[i]);
      	//pinMode( pines[7] , estado[7]);
      	//pinMode( boton , 0 );
      	//pinMode( 11 , INPUT);
}
    Serial.begin(9600);
  

  
  	for(int x=0 ; x<10 ;x++ )//recorre vec NUMEROS
    {
        for( int i=0; i<7 ; i++ )//recorre los HIGH y LOW 
        {      
          digitalWrite( pines[i] , numeros[7][i] );
} 
    	delay(500);
    }
  

}

void loop()
{
  	binario[3]=digitalRead(s1);
  	binario[2]=digitalRead(s2);
    binario[1]=digitalRead(s3);
    binario[0]=digitalRead(s4);
	Serial.print( binario[0]);
  	Serial.print( binario[1]);
  	Serial.print( binario[2]);
  	Serial.print( binario[3]);
  	Serial.print(" - ");
  	
  // 2^3  2^2  2^1  2^0
  //  8    4    2    1
  
  //  1    0    1    0   = 2
  //  8  + 0  + 2    0   = 10
int dec=0;
  for( int i=3; i>=0;i--)
  {
    //pow => raiz   pow(base, expo)   ->  numero float
    //round()  -> redondeo arriba  7.6  => 8.0
    // (int) -> casteo   =>  (7.6 -> 7)   (8.0 -> 8)
    dec = dec + ( binario[i] *  (int)round( pow(2,i) )  ) ;
  }
  Serial.println( dec );
  
  
  
  for( int i=0; i<7 ; i++ )//recorre los HIGH y LOW
{      
    digitalWrite( pines[i] , numeros[dec][i] );
  }   
  
  
}