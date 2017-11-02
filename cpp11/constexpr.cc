/**
 * constexpr: compiler will check if the variable is const at compile-time.
 *
 * constexpr makes the variable a top-level const
 *
 * @date Wed Nov  1 22:27:54 2017
 * @author Shi Wei (shiwei2012@gmail.com)
 */

constexpr int ci = 0;
constexpr int cc = ci;

int ni = 1;
constexpr int *p = &ni;
// compile error
//constexpr int *pp = &cc;
constexpr const int *q = &ci;

int main(int argc, char *argv[]) {
	return 0;
}
