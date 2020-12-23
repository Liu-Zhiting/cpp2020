#include "CNumberFactory.h"

class CNumber : public CNumberFactory
{
    private:
        int number;
    public:
        void SetValue(int number)
        {
            this->number = number;
        }

        int GetValue()
        {
            return this->number;
        }

        void Add(int number)
        {
            this->number += number;
        }

        void Sub(int number)
        {
            this->number -= number;
        }


};

CNumberFactory * CNumberFactory::Create()
{
    return new CNumber();
}