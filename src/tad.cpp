#include <iostream>
#include "tporo.h"
#include "tvectorporo.h"

using namespace std;
//redimensionar
int main(void){
	TVectorPoro v1(5);
	cout<<v1.Redimensionar(0)<<endl;
	cout<<v1.Redimensionar(-1)<<endl;
	cout<<v1.Redimensionar(5)<<endl;
	
	TPoro p1(1,2,3,"rojo");
	TPoro p2(1,2,3,"yellow");
	TPoro p3(1,2,3,"green");
	TPoro p4(1,2,3,"red");
	TPoro p5(1,2,3,"pink");
	v1[1]=p1;
	v1[2]=p2;
	v1[3]=p3;
	v1[4]=p4;
	v1[5]=p5;
	cout<<v1.Redimensionar(8)<<endl;
	cout<<v1.Longitud()<<endl;
	cout<<v1.Cantidad()<<endl;
	cout<<v1<<endl;

	cout<<v1.Redimensionar(3)<<endl;
	cout<<v1.Longitud()<<endl;
	cout<<v1.Cantidad()<<endl;
	cout<<v1<<endl;


}
