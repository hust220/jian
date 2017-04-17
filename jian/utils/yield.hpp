#pragma once

#include "traits.hpp"

#define itBegin switch(m_iter_state) { case 0:

#define yield_(x) do { m_iter_state=__LINE__; return x; \
    case __LINE__:; } while (0)

#define itEnd }

#define for_(a, b) do { auto jn_for_it = b; \
    for (auto a = jn_for_it(); a != NULL; a = jn_for_it())

#define end_ } while(0)

BEGIN_JN

struct IterBase {
    int m_iter_state;
    IterBase() : m_iter_state(0) {}
};

template<typename _Ls>
Int it_size(const _Ls &ls) {
    Int n = 0; for_(i, ls) n++; end_;
    return n;
}

// map of stl
template<typename _Out, typename _Fn, typename _In>
_Out map_j(_Fn && f, _In && in) {
    _Out out;
    for_ (i, in) {
        out.push_back(*i);
    } end_;
    return out;
}

END_JN

