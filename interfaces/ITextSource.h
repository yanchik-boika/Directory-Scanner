#ifndef ITEXTSOURCE_H
#define ITEXTSOURCE_H

template <typename T>
class ITextSource {
public:
    virtual void streamToProcessor(T& data) = 0;
    virtual ~ITextSource() = default;
};


#endif //ITEXTSOURCE_H
