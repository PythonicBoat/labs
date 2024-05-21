# Assign the arguments to variables
num1=$1
num2=$2

# Perform the operations
sum=$(echo "$num1 + $num2" | bc)
difference=$(echo "$num1 - $num2" | bc)
product=$(echo "$num1 * $num2" | bc)
quotient=$(echo "scale=2; $num1 / $num2" | bc)

# Print the results
echo "Sum: $sum"
echo "Difference: $difference"
echo "Product: $product"
echo "Quotient: $quotient"

#!/bin/bash

# Read the numbers
read -p "Enter number 1: " num1
read -p "Enter number 2: " num2

# Perform the operations
sum=$(echo "$num1 + $num2" | bc)
difference=$(echo "$num1 - $num2" | bc)
product=$(echo "$num1 * $num2" | bc)
quotient=$(echo "scale=2; $num1 / $num2" | bc)

# Print the results
echo "Sum: $sum"
echo "Difference: $difference"
echo "Product: $product"
echo "Quotient: $quotient"

# #!/bin/bash

# # Initialize variables
# sum=0
# count=0

# # Get 5 numbers from the user
# read -p "Enter number 1: " num
# sum=$((sum + num))  # Accumulate the sum
# count=$((count + 1))  # Increment the count

# read -p "Enter number 2: " num
# sum=$((sum + num))  # Accumulate the sum
# count=$((count + 1))  # Increment the count

# read -p "Enter number 3: " num
# sum=$((sum + num))  # Accumulate the sum
# count=$((count + 1))  # Increment the count

# read -p "Enter number 4: " num
# sum=$((sum + num))  # Accumulate the sum
# count=$((count + 1))  # Increment the count

# read -p "Enter number 5: " num
# sum=$((sum + num))  # Accumulate the sum
# count=$((count + 1))  # Increment the count

#     # Calculate the average using bc for decimal accuracy
#     average=$(echo "scale=2; $sum / $count" | bc -l)

#     # Display the average
#     echo "The average is: $average"

# # shell script to calculate area of rectangle, triangle and circle

# # calculate area of a rectangle
# echo -n "Enter length: "
# read length
# echo -n "Enter breadth: "
# read breadth
# rectArea=$(expr $length \* $breadth)
# echo "Area of rectangle is $rectArea"

# # calculate area of a triangle
# echo -n "Enter base: "
# read base
# echo -n "Enter height: "
# read height
# triArea=$(expr $base \* $height / 2)
# echo "Area of triangle is $triArea"

# # calculate area of a circle
# echo -n "Enter radius: "
# read radius
# circArea=$(expr $(( 4 \* 3.14 \* $radius \* $radius )) / 3)
# echo "Area of circle is $circArea"