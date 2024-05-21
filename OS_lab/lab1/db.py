def find_super_keys(attributes):
    num_super_keys = 2 ** len(attributes)
    return num_super_keys

# Example Usage:

# I.
R1_attributes = ['att1', 'att2']
num_super_keys_R1 = find_super_keys(R1_attributes)
print(f"Number of super keys for R1: {num_super_keys_R1}")

# II.
R2_attributes = ['att1', 'att2']
num_super_keys_R2 = find_super_keys(R2_attributes)
print(f"Number of super keys for R2: {num_super_keys_R2}")

# III.
R3_attributes = ['att1', 'att2', 'att3']
num_super_keys_R3 = find_super_keys(R3_attributes)
print(f"Number of super keys for R3: {num_super_keys_R3}")

# IV.
R4_attributes = ['att1', 'att2', 'att3']
num_super_keys_R4 = find_super_keys(R4_attributes)
print(f"Number of super keys for R4: {num_super_keys_R4}")

# V.
R5_attributes = ['att1']
num_super_keys_R5 = find_super_keys(R5_attributes)
print(f"Number of super keys for R5: {num_super_keys_R5}")

# VI.
R6_attributes = ['att1', 'att2', 'att3']
num_super_keys_R6 = find_super_keys(R6_attributes)
print(f"Number of super keys for R6: {num_super_keys_R6}")

# VII.
R7_attributes = ['att1', 'att2', 'att3', 'att4']
num_super_keys_R7 = find_super_keys(R7_attributes)
print(f"Number of super keys for R7: {num_super_keys_R7}")
