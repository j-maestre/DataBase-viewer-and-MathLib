#ifndef __MATHUTILS_H__
#define __MATHUTILS_H__ 1

class Mathf {
	public:
		static float Clamp(float value, float minVal, float maxVal);

	private:
		Mathf();
		Mathf(const Mathf& copy);
		~Mathf();
};
inline Mathf::Mathf() {}
inline Mathf::Mathf(const Mathf& copy) {}
inline Mathf::~Mathf(){}

inline float Mathf::Clamp(float value, float minVal, float maxVal) {
	return 0.0f;
}
#endif