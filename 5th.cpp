import random

def generate_keypair(p, q):
    # Step 1: Key Generation
    n = p * q
    phi = (p - 1) * (q - 1)

    # Choose a public exponent e
    e = random.randint(1, phi)
    # Verify that e and phi(n) are coprime
    while gcd(e, phi) != 1:
        e = random.randint(1, phi)

    # Calculate the private exponent d
    d = mod_inverse(e, phi)

    # Return public and private keys
    return ((e, n), (d, n))

def gcd(a, b):
    # Calculate the Greatest Common Divisor (GCD) of two numbers
    while b != 0:
        a, b = b, a % b
    return a

def mod_inverse(a, m):
    # Calculate the modular multiplicative inverse of a modulo m
    r, old_r = m, a
    x, old_x = 0, 1

    while r != 0:
        quotient = old_r // r
        old_r, r = r, old_r - quotient * r
        old_x, x = x, old_x - quotient * x

    if old_r > 1:
        raise ValueError("Inverse does not exist.")
    
    return old_x % m

def encrypt(public_key, message):
    # Step 2: Encryption
    e, n = public_key
    ciphertext = [pow(ord(char), e, n) for char in message]
    return ciphertext

def decrypt(private_key, ciphertext):
    # Step 3: Decryption
    d, n = private_key
    plaintext = ''.join([chr(pow(char, d, n)) for char in ciphertext])
    return plaintext

