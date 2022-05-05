 #include <iostream>
 #include <ctime>
 #include <armadillo>
  
//   compile
// g++ testarma.cpp -o testarma -DARMA_USE_WRAPPER -lopenblas -llapack -L/usr/lib/x86_64-linux-gnu/hdf5/serial -lhdf5
// execute
// ./testarma


int main(){
    arma::mat A;

    A <<1<<2<<arma::endr
      <<3<<4;
    std::cout<<A<<std::endl;

    arma::fmat B;
    time_t s1,e1;
    s1=time(NULL);
    B.randu(1000000000);
    e1=time(NULL);
    std::cout<<e1-s1<< "seconds";
    B<<1;
    std::cout<<std::endl<<"B "<<B;
    
}

//  int main(int argc, const char **argv) {
//       // Initialize the random generator
//       arma::arma_rng::set_seed_random();
  
//       // Create a 4x4 random matrix and print it on the screen
//       arma::Mat<double> A = arma::randu(4,4);
//      std::cout << "A:\n" << A << "\n";
 
//      // Multiply A with his transpose:
//      std::cout << "A * A.t() =\n";
//      std::cout << A * A.t() << "\n";
 
//      // Access/Modify rows and columns from the array:
//      A.row(0) = A.row(1) + A.row(3);
//      A.col(3).zeros();
//      std::cout << "add rows 1 and 3, store result in row 0, also fill 4th column with zeros:\n";
//      std::cout << "A:\n" << A << "\n";
 
//      // Create a new diagonal matrix using the main diagonal of A:
//      arma::Mat<double>B = arma::diagmat(A);
//      std::cout << "B:\n" << B << "\n";
 
//      // Save matrices A and B:
//      A.save("A_mat.txt", arma::arma_ascii);
//      B.save("B_mat.txt", arma::arma_ascii);
 
//      return 0;
//  }