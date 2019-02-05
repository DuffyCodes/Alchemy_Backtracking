# Alchemy_Backtracking 
This was taken from my course. It was a week long project. My code is all in the findMaxTemp.cpp file
1.1 Input
The input begins with a list of up to 64 pairs of chemicals and the heat they produce. This consists of multiple lines, each of the form

chemical1 chemical2 heat

where chemical1 and chemical2 are names of chemicals, expressed as an alphabetic string of 1-20 characters. heat is an integer in the range 0…100 indicating the number of degrees by which the temperature in the jar will rise when 1 gram of chemical1 mixes with one gram of chemical2.

The order in which the two chemicals appear within a single line is not relevant.

No pair of chemicals will appear more than once in this list.

This list of pairs is terminated by a line containing “0 0 0”.

It is followed by a list of up to 12 chemicals that Frederico plans to place in the jar. The list consists of a number of lines of the form

chemical amount

where chemical is the name of a chemical (again, expressed as an alphabetic string of 1-20 characters) and amount is an integer in the range 0…1000 indicating the quantity (in grams) to be disposed. No chemical will appear more than once in this second list.

This list is terminated by a line containing “0 0”.

2 Output
Print a single line of output of the form

The temperature in the jar will change by at most M degrees.

where M is an integer indicating the maximum temperature rise.

2.1 Examples
For example, if the input is

Aqua Beta 2
Beta Calcum 1
Aqua Delta 10
Ente Franca 10
0 0 0
Aqua 50
Calcum 10
Beta 25
Delta 10
Franca 10
0 0
the output would be

The temperature in the jar will change by at most 150 degrees.
