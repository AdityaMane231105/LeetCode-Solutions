class Solution(object):
    def divide(self, dividend, divisor):
        """
        :type dividend: int
        :type divisor: int
        :rtype: int
        """
        # Constants for 32-bit integer limits
        MAX_INT = 2147483647
        MIN_INT = -2147483648

        # Handle overflow case: -2^31 / -1 = 2^31 (which overflows)
        if dividend == MIN_INT and divisor == -1:
            return MAX_INT

        # Determine the sign of the result
        # If signs are different, result is negative
        negative = (dividend < 0) != (divisor < 0)

        # Work with absolute values to simplify logic
        dividend = abs(dividend)
        divisor = abs(divisor)
        
        quotient = 0

        # Bit manipulation approach (Exponential search)
        while dividend >= divisor:
            temp_divisor = divisor
            multiple = 1
            # Double the divisor until it's larger than the remaining dividend
            while dividend >= (temp_divisor << 1):
                temp_divisor <<= 1
                multiple <<= 1
            
            # Subtract the largest found multiple of divisor from dividend
            dividend -= temp_divisor
            quotient += multiple

        # Apply the sign and ensure the result is within 32-bit range
        return -quotient if negative else quotient
