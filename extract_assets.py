import re
import os

def extract_and_convert_assets(input_file, output_folder):
    """
    Extracts the 'assets' byte array from a C source file, converts it to a binary file.

    Args:
        input_file (str): Path to the C source file (e.g., 'src/ui/ui.c').
        output_folder (str): Path to the folder where the binary file will be saved.
    """
    try:
        with open(input_file, 'r') as f:
            content = f.read()

        # Regex to find the assets array content
        match = re.search(r'const\s+uint8_t\s+assets\[\d+\]\s*=\s*\{([^}]+)\};', content, re.DOTALL)

        if not match:
            print(f"Error: 'assets' array not found in {input_file}")
            return

        # Extract the comma-separated hex values
        hex_values_str = match.group(1)
        
        # Clean up the string: remove comments, newlines, and spaces
        hex_values_str = re.sub(r'//.*', '', hex_values_str) # Remove C++ style comments
        hex_values_str = re.sub(r'/\*.*?\*/', '', hex_values_str, re.DOTALL) # Remove C style comments
        hex_values_str = hex_values_str.replace('\n', '').replace('\r', '')

        # Find all hex values (e.g., 0xAB, 0xFF)
        hex_values = re.findall(r'0x[0-9a-fA-F]{1,2}', hex_values_str)

        if not hex_values:
            print("Error: No hex values found in the assets array.")
            return
            
        # Convert hex strings to integers and then to bytes
        byte_data = bytearray(int(val, 16) for val in hex_values)

        # Ensure the output directory exists
        if not os.path.exists(output_folder):
            os.makedirs(output_folder)

        # Write to the binary file
        output_file_path = os.path.join(output_folder, 'assets.bin')
        with open(output_file_path, 'wb') as f_out:
            f_out.write(byte_data)

        print(f"Successfully extracted {len(byte_data)} bytes to {output_file_path}")

    except FileNotFoundError:
        print(f"Error: The file {input_file} was not found.")
    except Exception as e:
        print(f"An unexpected error occurred: {e}")

if __name__ == "__main__":
    # Assuming the script is in the root of the PlatformIO project
    c_file_path = 'src/ui/ui.c'
    output_dir = 'data'
    extract_and_convert_assets(c_file_path, output_dir)
