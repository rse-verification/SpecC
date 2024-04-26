""" This module tests a function that is generated using gcc"""
import os
import subprocess
from io import StringIO
import pandas as pd

def test_generated_code(path_file, path_test):
    """ Function that tests a generated file
    Args:
        path_file: The path to the generated file
        path_test: The path to the test file
    Returns:
        The amount of tests that passed
        The total amount of tests"""

    # Remove ../ from the paths
    path_file = os.path.normpath(path_file)
    path_test = os.path.normpath(path_test)

    # Create the output directory if it does not exist
    output_path = os.path.join(*path_file.split("/")[:-1])
    if not os.path.exists(output_path):
        os.makedirs(output_path)

    path_to_executable = os.path.join(output_path, f"test")

    # Compile the file and the test cases
    subprocess.Popen(["gcc", path_file, path_test, "-o", path_to_executable],
                                stdout=subprocess.PIPE, stderr=subprocess.PIPE)

    # Name for the output of the test cases
    output_tests_path =  os.path.join(output_path, "output_tests.json")

    # Run the test cases
    subprocess.Popen([path_to_executable, output_tests_path], stdout=subprocess.PIPE, stderr=subprocess.PIPE)

    # Remove the executable
    os.system(f"rm '{path_to_executable}'")


    # Print the output of the test cases by reading the output file
    with open(output_tests_path, "r") as file:
        # Read the test output as a pandas json
        tests_output = pd.read_json(StringIO(file.read()))

        # Print the last row
        test_information = tests_output.iloc[-1]['summary']
        passed = test_information['passed']
        total = test_information['total']

    return passed, total, tests_output.to_dict()
