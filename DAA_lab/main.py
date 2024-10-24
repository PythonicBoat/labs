import pandas as pd
import sys

# Get the file name from the command-line arguments
if len(sys.argv) < 2:
    print("Usage: python main.py <file_name>")
    sys.exit(1)

file_name = sys.argv[1]

# Initialize an empty dictionary to store committee-wise country lists
committee_countries = {}

# Define the sheet names
sheet_names = {'Sheet1', 'Sheet2'}  # Replace with actual sheet names if known

# Iterate through each sheet, assuming the first column contains the country names
for sheet in sheet_names:
    # Load the data from the current sheet
    df = pd.read_excel(file_name, sheet_name=sheet)
    
    # Extract the first column as the list of countries
    countries = df.iloc[:, 0].dropna().tolist()  # Drop any NaN values just in case
    
    # Store the countries list in the dictionary with the committee name as the key
    committee_countries[sheet] = countries

# Format the data in the desired JavaScript object syntax
formatted_output = "const committeeCountries: { [key in Committee]: string[] } = {\n"
for committee, countries in committee_countries.items():
    formatted_output += f"  [Committee.{committee.upper()}]: [\n"
    for country in countries:
        formatted_output += f"      \"{country}\",\n"
    formatted_output = formatted_output.rstrip(",\n") + "\n  ],\n"
formatted_output = formatted_output.rstrip(",\n") + "\n};"

# Print the formatted output
print(formatted_output)