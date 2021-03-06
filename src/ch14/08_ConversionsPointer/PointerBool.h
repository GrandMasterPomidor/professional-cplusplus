#ifndef POINTERBOOL_H
#define POINTERBOOL_H

template <typename T>
class Pointer {
public:
  Pointer(T* inPtr);
  virtual ~Pointer();

  // Prevent assignment and pass by value.
  Pointer(const Pointer<T>& src) = delete;
  Pointer<T>& operator=(const Pointer<T>& rhs) = delete;

  T& operator*();
  const T& operator*() const;

  T* operator->();
  const T* operator->() const;

  operator bool() const { return mPtr != nullptr; }

  // template <typename T>
  // friend bool operator!=(const Pointer<T>& lhs, const std::nullptr_t& rhs);

private:
  T* mPtr;
};

// template <typename T>
// bool operator!=(const Pointer<T>& lhs, const std::nullptr_t& rhs)
//{
//	return lhs.mPtr != rhs;
//}

template <typename T>
Pointer<T>::Pointer(T* inPtr) : mPtr(inPtr) {}

template <typename T>
Pointer<T>::~Pointer() {
  delete mPtr;
  mPtr = nullptr;
}

template <typename T>
T& Pointer<T>::operator*() {
  return *mPtr;
}

template <typename T>
const T& Pointer<T>::operator*() const {
  return *mPtr;
}

template <typename T>
T* Pointer<T>::operator->() {
  return mPtr;
}

template <typename T>
const T* Pointer<T>::operator->() const {
  return mPtr;
}

#endif /* POINTERBOOL_H */
