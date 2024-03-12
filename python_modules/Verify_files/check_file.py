""" This module is used to check a C file in a given directory"""
import sys
from Verify_files.compile_file import compile_c
from Verify_files.verify_file import verify_file
import os

def check_file(absolute_path_to_c_file, absolute_path_to_h_file, args):
    """Check a C file in a given directory
    Args:
        args: The arguments given to the program
        file_name_c: The name of the C file
        file_name_h: The name of the header file
    Returns:
        True if the C file verified successfully, False otherwise
        If the file did not verify, the output of the verification"""
    print(f"Files {absolute_path_to_c_file.split('/')[-1]} and " + 
          f"{absolute_path_to_c_file.split('/')[-1]} exists, starting to compile...")

    # Compile the file
    # Get the directory of absolute_path_to_c_file
    absolute_output_dir = os.path.join(*absolute_path_to_c_file.split("/")[:-1])
    result, output = compile_c(absolute_path_to_c_file, absolute_output_dir)
    if result is False:
        print(f"Compilation of file {absolute_path_to_h_file.split('/')[-1]} failed," + 
              f"Error:\n {output}")
        sys.exit()
    else:
        print(f"File {absolute_path_to_c_file.split('/')[-1]} compiled successfully")

    print(f"File {absolute_path_to_c_file.split('/')[-1]} will be verified...")

    # Verify the file
    return verify_file(args)
