/**
 * cpp11: delete constructors
 *
 * @date Thu Nov  9 10:25:45 2017
 * @author Shi Wei (shiwei2012@gmail.com)
 */

class D {
 public:
  D() = default;

  D(const D &d) = delete;
  D &operator=(const D &d) = delete;
};

int main(void) {
  D d;
  D e;

	// compile error
  //D f(d);
  //D g = e;

  return 0;
}
