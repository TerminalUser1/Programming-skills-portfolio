# Challenge 1 - CO2 Calculator

I started by working out how much fuel the car would use. The brief says the car uses 9.66 litres for every 100 miles. I divided the distance by 100 and multiplied it by 9.66. I put this calculation in `calculateEmissions()`. To get the CO2 in kilograms, the function multiplies the litres used by 2.68 for diesel or 2.31 for petrol.

I used two other functions to get the information from the user. `getDistance()` asks for the distance in miles. I used a `double` because someone might enter a distance like 12.5 miles. The function reads the whole line and asks again if the distance is negative or the user types something like `12abc`. I let the user enter zero because a journey of zero miles would give zero emissions.

In `getFuelType()`, the user enters 1 for diesel or 2 for petrol. If they enter anything else, the program asks them to choose again. Once both answers are valid, `main()` calls the calculation function and shows the result to two decimal places. To check the maths, I used 100 miles because that works out to exactly 9.66 litres. The program showed 25.89 kg for diesel and 22.31 kg for petrol.
