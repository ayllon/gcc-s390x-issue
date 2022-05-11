#ifndef ELEMENTSKERNEL_ELEMENTSKERNEL_REAL_H_
#define ELEMENTSKERNEL_ELEMENTSKERNEL_REAL_H_

#include <cassert>
#include <cmath>       // for round
#include <limits>      // for numeric_limits
#include <type_traits> // for is_floating_point

#define ELEMENTS_API
#define ELEMENTS_UNUSED

using std::numeric_limits;

namespace Elements {

/// Double precision float default maximum unit in the last place
constexpr std::size_t DBL_DEFAULT_MAX_ULPS{10};

template <std::size_t size> class ELEMENTS_API TypeWithSize {
public:
  // This prevents the user from using TypeWithSize<N> with incorrect
  // values of N.
  using UInt = void;
};

// The specialisation for size 8.
template <> class ELEMENTS_API TypeWithSize<8> {
public:
  using UInt = unsigned long long; // NOLINT
};

// This template class represents an IEEE floating-point number
// (either single-precision or double-precision, depending on the
// template parameters).
//
// The purpose of this class is to do more sophisticated number
// comparison.  (Due to round-off error, etc, it's very unlikely that
// two floating-points will be equal exactly.  Hence a naive
// comparison by the == operation often doesn't work.)
//
// Format of IEEE floating-point:
//
//   The most-significant bit being the leftmost, an IEEE
//   floating-point looks like
//
//     sign_bit exponent_bits fraction_bits
//
//   Here, sign_bit is a single bit that designates the sign of the
//   number.
//
//   For float, there are 8 exponent bits and 23 fraction bits.
//
//   For double, there are 11 exponent bits and 52 fraction bits.
//
//   More details can be found at
//   http://en.wikipedia.org/wiki/IEEE_floating-point_standard.
//
// Template parameter:
//
//   double: the raw floating-point type (either float or double)
class ELEMENTS_API FloatingPoint {
public:
  // Defines the unsigned integer type that has the same size as the
  // floating point number.
  using Bits = typename TypeWithSize<sizeof(double)>::UInt;

  // Constants.

  // # of bits in a number.
  static const std::size_t s_bitcount = 8 * sizeof(double);

  // The mask for the sign bit.
  static const Bits s_sign_bitmask = static_cast<Bits>(1) << (s_bitcount - 1);

  // Converts an integer from the sign-and-magnitude representation to
  // the biased representation.  More precisely, let N be 2 to the
  // power of (kBitCount - 1), an integer x is represented by the
  // unsigned number x + N.
  //
  // For instance,
  //
  //   -N + 1 (the most negative number representable using
  //          sign-and-magnitude) is represented by 1;
  //   0      is represented by N; and
  //   N - 1  (the biggest number representable using
  //          sign-and-magnitude) is represented by 2N - 1.
  //
  // Read http://en.wikipedia.org/wiki/Signed_number_representations
  // for more details on signed number representations.
  static Bits signAndMagnitudeToBiased(const Bits &sam) {
    if (s_sign_bitmask & sam) {
      // sam represents a negative number.
      return ~sam + 1;
    } else {
      // sam represents a positive number.
      return s_sign_bitmask | sam;
    }
  }

  // Given two numbers in the sign-and-magnitude representation,
  // returns the distance between them as an unsigned number.
  static Bits distanceBetweenSignAndMagnitudeNumbers(const Bits &sam1,
                                                     const Bits &sam2) {
    const Bits biased1 = signAndMagnitudeToBiased(sam1);
    const Bits biased2 = signAndMagnitudeToBiased(sam2);
    return (biased1 >= biased2) ? (biased1 - biased2) : (biased2 - biased1);
  }

private:
};

bool isEqual(const double &left, const double &right) {
  using Bits = typename TypeWithSize<sizeof(double)>::UInt;
  Bits l_bits = *reinterpret_cast<const Bits *>(&left);
  Bits r_bits = *reinterpret_cast<const Bits *>(&right);

  return FloatingPoint::distanceBetweenSignAndMagnitudeNumbers(
             l_bits, r_bits) <= DBL_DEFAULT_MAX_ULPS;
}

} // namespace Elements

#endif // ELEMENTSKERNEL_ELEMENTSKERNEL_REAL_H_

/**@}*/
