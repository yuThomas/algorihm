//single instance designed under Linux

class CSingleton
{
pulibc:
    static shared_ptr<CSingleton> CreateInstance();

private:
    static shared_ptr<CSingleton> m_instance;
    static pthread_once_t m_onceKey;

private:
    static void _CreateInstance();
    CSingleton(){}
    CSingleton& operator(const CSingleton &);
    CSingleton(const CSingleton&);
};

pthread_once_t CSingleton::m_onceKey = PTHREAD_ONCE_INIT;
shared_ptr<CSingleton> CSingleton::m_instance = NULL;
shared_ptr<CSingleton> CSingleton::CreateInstance()
{
    pthread_once(&m_onceKey, _CreateInstance); //only one thread execute function _CreateInsatance under multi-threadings enviroment
    return m_instance;
}

void CSingleton::_CreateInstance()
{
   m_instance = shared_ptr<CSingleton>(new CSingleton);
}
