#include <iostream>
#include <math.h>

class ComplexNum {
private:
 double mRe = 0;
 double mIm = 0;
public:
 ComplexNum();
 ComplexNum(const double& a){
   mRe = a;
 }
 ComplexNum(const double& a, const double& b){
   mRe = a;
   mIm = b;
 }

 double getModulus(){
   return sqrt(mRe*mRe + mIm*mIm);
 }

 double getRe() const{
   return mRe;
 }

 double getIm() const{
   return mIm;
 }

 //// Overload operators:
 //  
ComplexNum operator+(const ComplexNum& c){
  mRe = mRe + c.getRe();
  mIm = mIm + c.getIm();
  return *this;
}
ComplexNum operator-(const ComplexNum& c){
  mRe = mRe - c.getRe();
  mIm = mIm - c.getIm();
  return *this;
}

ComplexNum operator*(int k){
  mRe = mRe * k;
  mIm = mIm * k;
  return *this;
}
std::ostream& operator<<(std::ostream &out){
  out << "(" << mRe << "," << mIm << ")" << std::endl;
  return out;
}

};

int main(){
  int N;
  std::cout << "amount of complex number: " << std::endl;
  std::cin >> N;
  std::cout << "enter complex numbers: " << std::endl;
  double a,b;
  double arr[N];
  for(int i= 0; i < N; i++){
    std::cin >> a;
    std::cin >> b;
    ComplexNum c(a,b);
    arr[i] = c.getModulus();
  }
  for (int i = 0; i < N - 1; i++) {
    for (int j = 0; j < N - i - 1; j++) {
        if (arr[j] > arr[j + 1]) {
            double temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
        }
    }
  }

  std::cout << "sorted by modul complex number";

  for (int i = 0; i < N; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
  
  return 0;
}
