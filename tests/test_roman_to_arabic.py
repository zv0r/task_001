from subprocess import run, PIPE
import os
import pytest


def test_roman_to_arabic_MMXXIV():
    result = run(['./src/roman_to_arabic'], input='MMXXIV', encoding='utf-8', stdout=PIPE)
    assert result.returncode == 0
    assert int(result.stdout.strip()) == 2024


def test_roman_to_arabic_MMCCLXXXVIII():
    result = run(['./src/roman_to_arabic'], input='MMCCLXXXVIII', encoding='utf-8', stdout=PIPE)
    assert result.returncode == 0
    assert int(result.stdout.strip()) == 2288


def test_roman_to_arabic_I():
    result = run(['./src/roman_to_arabic'], input='I', encoding='utf-8', stdout=PIPE)
    assert result.returncode == 0
    assert int(result.stdout.strip()) == 1


def test_src_folder_contains_roman_to_arabic_c():
    assert os.path.isfile('./src/roman_to_arabic.c')


def test_src_folder_contains_roman_to_arabic_c_correct_name():
    assert os.path.basename('./src/roman_to_arabic.c') == 'roman_to_arabic.c'


if __name__ == "__main__":
    pytest.main()
