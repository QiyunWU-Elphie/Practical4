#include <iostream>
using namespace std;

double * read_poly(int &n){
  cout << "il grado: ";
  cin >> n;
  double * c=new double[n+1];
  for(int i=0;i<=n;i++){
    cout << "Coefficient of degree " << i << ": ";
    cin >> c[i];
  }
  return c;
}

void print_poly(double *c, int n){
  int i;
  cout << c[0];
  if(n>0)
    cout << " + ";
  for(i=1;i<n;i++)
    cout << c[i] << "*x^" << i << " + ";
  if(n>0)
    cout << c[n] << "*x^" << i;
  cout << endl;
}

int pow(int x, int y){
  int i;
  int result=1;
  for(i=0;i<y;i++){
    result*=x;
  }
  return result;
}

double poli_value (double * p1, int d1, int x){
  //calculate the value for certain position x;
  double result=0;
  for(int i=0;i<=d1;i++){
    result+=pow(x,i)*p1[i];
  }
  return result;
}

double * poli_sum (double * p1, int d1, double * p2, int d2, int & dr){
  if(d1>d2) dr=d1;
  else dr=d2;
  double * c=new double[dr+1];
  for(int i=0;i<=dr;i++){
    cout<<"i= "<<i<<"p1[i]= "<<p1[i]<<"p2[i]= "<<p2[i]<<endl;
    c[i]=p1[i]+p2[i];
  }
  return c;
}

double * poli_product (double * p1, int d1, double * p2, int d2, int & dr){
  dr=d1+d2;
  double * c=new double[dr+1];
  for(int i=0;i<=dr;i++) c[i]=0;
  for(int i=0;i<=d1;i++){
    for(int j=0;j<=d2;j++){
      c[i+j]+=p1[i]*p2[j];
    }
  }
  return c;
}

int main()
{
  double *p1, *p2;
  int g1,g2;
  int i;
  double result;
  //p1=read_poly(g1);
  while(1){
    cout<<"1.Calculation of the polynomial value for a certain position x"<<endl;
    cout<<"2.Sum of two polynomials"<<endl;
    cout<<"3.Product of two polynomials"<<endl;
    cout<<"4.Exit"<<endl;
    cout<<"Please select: ";
    cin>>i;
    if(i==1){
      int x;
      cout<<"Please input the polynomial"<<endl;
      p1=read_poly(g1);
      cout<<"x= ";
      cin>>x;
      result = poli_value(p1, g1, x);
      cout<<"The result = "<<result<<endl;
      delete[] p1;
    }
    else if(i==2){
      cout<<"Please input the 1st polynomial"<<endl;
      p1=read_poly(g1);
      cout<<"Please input the 2nd polynomial"<<endl;
      p2=read_poly(g2);
      int dr;
      double * sum = poli_sum(p1,g1,p2,g2,dr);
      print_poly(sum, dr);
      delete[] p1;
      delete[] p2;
      delete[] sum;
    }
    else if(i==3){
      cout<<"Please input the 1st polynomial"<<endl;
      p1=read_poly(g1);
      cout<<"Please input the 2nd polynomial"<<endl;
      p2=read_poly(g2);
      int dr;
      double * product = poli_product(p1,g1,p2,g2,dr);
      print_poly(product, dr);
      delete[] p1;
      delete[] p2;
      delete[] product;
    }
    else if(i==4) break;
    else cout<<"Invalid value, please input again."<<endl;
  }
  return 0;
}
