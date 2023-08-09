#ifndef FEMALE_INTERPOLATIONFUNCTIONSLAGRANGE_HPP
#define FEMALE_INTERPOLATIONFUNCTIONSLAGRANGE_HPP

#include <array>
#include <functional>


// The interpolation functions are based in range of [-1,1]
namespace female::math::interp{
    template<int order > 
    class Lagrange{
        public:
            using func_t  = std::function<double(double)>;
            using funcs_t = std::array<func_t,order>;

            Lagrange( const funcs_t& funcs);
            Lagrange( const funcs_t& funcs, const funcs_t& dfuncs);

            std::size_t size() const;

            const func_t&  func(int i) const;
            const func_t& dfunc(int i) const;
            

        private:
            funcs_t m_f;
            funcs_t m_df;
    };
    ///////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////

    template<int order>
    Lagrange<order>::Lagrange(const Lagrange::funcs_t& funcs, const Lagrange::funcs_t& dfuncs):
    m_f(funcs), m_df(dfuncs)
    {}
    //-----------------------------------------------------
    //-----------------------------------------------------

    template<int order>
    Lagrange<order>::Lagrange(const Lagrange::funcs_t& funcs):
    m_f(funcs)
    {
        for(int i = 0; i < order; ++i){
            m_df[i] = [this,i](double x){ return (m_f[i](x+1.e-10) - m_f[i](x))/1.e-10; };
        }
    }
    //-----------------------------------------------------
    //-----------------------------------------------------

    template<int order>
    std::size_t Lagrange<order>::size() const {
        return order;
    }
    //-----------------------------------------------------
    //-----------------------------------------------------

    template<int order>
    const typename Lagrange<order>::func_t& Lagrange<order>::func(int i) const {
        return m_f[i];
    }
    //-----------------------------------------------------
    //-----------------------------------------------------

    template<int order>
    const typename Lagrange<order>::func_t& Lagrange<order>::dfunc(int i) const {
        return m_df[i];
    }
    //-----------------------------------------------------
    //-----------------------------------------------------



}



#endif