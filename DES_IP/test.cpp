
#include <vector> 
#include <iostream>


int main() 
{
	 std::vector<char> vec( 64, '0' ); 

	 for( int i = 0; i < vec.size(); ++i ) 

		 std::cout  << vec[ i ] ;

	 std::cout << std::endl;
}
