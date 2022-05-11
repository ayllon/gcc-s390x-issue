#ifndef ELEMENTSKERNEL_ELEMENTSKERNEL_REAL_H_
#define ELEMENTSKERNEL_ELEMENTSKERNEL_REAL_H_

#include <cassert>
#include <cmath> // for round
#include <cstdint>
#include <limits>      // for numeric_limits
#include <type_traits> // for is_floating_point

#define ELEMENTS_API
#define ELEMENTS_UNUSED

using std::numeric_limits;

namespace Elements {

/// Double precision float default maximum unit in the last place
constexpr std::size_t DBL_DEFAULT_MAX_ULPS{10};

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
//     sign_bit exponent_uint64_t fraction_uint64_t
//
//   Here, sign_bit is a single bit that designates the sign of the
//   number.
//
//   For float, there are 8 exponent uint64_t and 23 fraction uint64_t.
//
//   For double, there are 11 exponent uint64_t and 52 fraction uint64_t.
//
//   More details can be found at
//   http://en.wikipedia.org/wiki/IEEE_floating-point_standard.
//
// Template parameter:
//
//   double: the raw floating-point type (either float or double)
class ELEMENTS_API FloatingPoint {
public:
  // Constants.

  // # of uint64_t in a number.
  static const std::size_t s_bitcount = 8 * sizeof(double);

  // The mask for the sign bit.
  static const uint64_t s_sign_bitmask = static_cast<uint64_t>(1) << (s_bitcount - 1);

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
  static uint64_t signAndMagnitudeToBiased(const uint64_t &sam) {
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
  static uint64_t distanceBetweenSignAndMagnitudeNumbers(const uint64_t &sam1,
                                                     const uint64_t &sam2) {
    const uint64_t biased1 = signAndMagnitudeToBiased(sam1);
    const uint64_t biased2 = signAndMagnitudeToBiased(sam2);
    return (biased1 >= biased2) ? (biased1 - biased2) : (biased2 - biased1);
  }

private:
};

bool isEqual(const double &left, const double &right) {
  static_assert(sizeof(uint64_t) == sizeof(double));

  uint64_t l_uint64_t = *reinterpret_cast<const uint64_t *>(&left);
  uint64_t r_uint64_t = *reinterpret_cast<const uint64_t *>(&right);

  return FloatingPoint::distanceBetweenSignAndMagnitudeNumbers(
             l_uint64_t, r_uint64_t) <= DBL_DEFAULT_MAX_ULPS;
}

} // namespace Elements

#endif // ELEMENTSKERNEL_ELEMENTSKERNEL_REAL_H_

/**@}*/
