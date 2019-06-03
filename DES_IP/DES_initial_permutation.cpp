
#include "DES_initial_permutation.hpp"

int main()
{
 	DES_IP D; 

	std::string binary = D.conversion();

	std::vector<int> permute_vec_1 = D.initial_permutation();
	
	std::vector<char> permute_vec_2 = D.permutation_vector(permute_vec_1, binary);
	
	std::string conversion = D.conversion_to_hexadecimal(permute_vec_2); 

	std::cout << "\n" << "The Encrypted data is: " << conversion << std::endl;

	return 0;
}	

// Conversation from hexadecimal to binary
std::string DES_IP::binary_conversion( auto & ch ) 
{
	std::cout <<"Calling binary_conversion( auto & ch ) = " << std::endl;
	std::string binary;

        auto char_in_map = conversion_map_bin.find(tolower(ch));

        if( char_in_map != conversion_map_bin.end() ) {

               binary = char_in_map->second;
        }

        return binary;
	

} // end function 

// Get a string token from the user
// and proceed for the conversion
std::string DES_IP::conversion() 
{
	std::cout <<"Calling conversion()" << std::endl;

	std::string input_string; 
 	std::cout << "Enter a String: " << "\n" << std::endl; 

	std::getline( std::cin, input_string ); 
	std::string binary; 

	// Use a for loop to loop throughout the input string 
	for( int i = 0; i < input_string.size(); ++i )

		// Convert the string enter in binary
		binary += binary_conversion(  input_string[ i ] );

	return binary;

} // end function

// This function is used to perform the initial permutation
std::vector<int> DES_IP::initial_permutation()
{
	 std::cout <<"Calling initial_permuation()" << std::endl;

	// Proceed by storing the first raw of the permutation
	int initial_permutation[ 8 ] = { 58, 60, 62, 64, 57, 59, 61, 63 };

	// Create a vector to store the permutation numbers
	std::vector<int>  permutation_numbers;

	for( int i = 0; i < 8; ++i )
	{
		for( int j = 0; j < 8; ++j )
		{
			// Put the sequence of numbers in the container after subtracting 
			// 8 according to the initial permutation
			permutation_numbers.push_back( initial_permutation[ i ] - ( j * 8 ) );
		
		} // end for loop
	
	} // end for loop

	return permutation_numbers;

} // end function

/* This function is used to insert the bits where they belong to
 * according to the initial permutation table 
 * 
 * @param1: permute_vec 
 * @param2: binary
 *
*/
std::vector<char> DES_IP::permutation_vector( std::vector<int> &  permute_vec, std::string & binary )
{
	std::cout <<"Calling permutation_vector( std::vector<int> & permute_vec, std::string & binary )" << std::endl;

	// Create a vector of size 64 fill with '0'
	std::vector<char> intial_permutation_vec( 64, '0');

	//  Get each character within the string
	for( int i = 0; i < binary.size(); ++i )
	{
		// Loop throughout each element in then permutation vector  
		for( int j = 0; j < permute_vec.size(); ++j ) 
		{
			// If the index of the first element in the vector is ( i + 1 )
			// Get it and put it in the position that it belongs 
			// according to the initial permutation structure
			if( permute_vec[ j ] == i + 1 )
			{
			 	intial_permutation_vec[ j ] = binary[ i ];
			
			} // end if
		} // end for

	} // end for 

	return intial_permutation_vec; // return the vector that contains the bits that are permutated
	
} // end function


/* This function is used for the conversion from binary to hexadecimal
 *
 * @param: bin_digit is a binary representation that needs to be converted
 *
 */
std::string DES_IP::binary_to_hexadecimal( std::string & bin_digit )
{
	std::cout <<"Calling binary_to_hexadecimal( std::string & bin_digit )" << std::endl;

	std::string hexadecimal;
	//std::string binary; 

	auto binary = conversion_map_hex.find( bin_digit );
	
	if( binary != conversion_map_hex.end() ) { 

		hexadecimal = binary->second;
	}

	return hexadecimal;

}

/* This function is used to convert the permutated bits to hexadecimal.
 * In order words, the converstion of the binary representation to hexadecimal
 *
 * @param: binary_vec is a container with the binary representation
 *
 */
std::string DES_IP::conversion_to_hexadecimal( std::vector< char > & binary_vec ) 
{
	std::cout <<"Calling conversion_to_hexadecimal( std::vector< char > & binary_vec ) " << std::endl;

	// Create to gather a 4 bits string and convert them in hexadecimal 
	std::string four_digit, hexadecimal;

	// This for loop is used to get 4 digit at the same time 
	for( int i = 0; i < binary_vec.size(); i += 4 )
	{
		// Make sure to not exceed 4 digits
		if( i + 3 >  binary_vec.size() )

			break;

		// Concatenat a sequence of string
		std::stringstream ss; 

		// Get the 4 digit string
		ss <<  binary_vec[ i ] << binary_vec[ i + 1 ] << binary_vec[ i + 2 ] << binary_vec[ i + 3 ]; 
		four_digit = ss.str();

		// Convert the 4 digit in hexadecimal
		hexadecimal += binary_to_hexadecimal(four_digit);

	} // end for

	return hexadecimal;

} // end function 


