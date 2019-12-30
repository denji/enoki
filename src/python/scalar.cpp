#include "common.h"

extern void bind_scalar_0d(py::module&, py::module&);
extern void bind_scalar_1d(py::module&, py::module&);
extern void bind_scalar_2d(py::module&, py::module&);
extern void bind_scalar_3d(py::module&, py::module&);
extern void bind_scalar_4d(py::module&, py::module&);
extern void bind_scalar_complex(py::module&, py::module&);
extern void bind_scalar_matrix(py::module&, py::module&);
extern void bind_scalar_pcg32(py::module&, py::module&);

bool *implicit_conversion = nullptr;

PYBIND11_MODULE(scalar, s) {
    py::module m = py::module::import("enoki");

    implicit_conversion = (bool *) py::get_shared_data("implicit_conversion");

    s.attr("Mask")    = py::handle((PyObject *) &PyBool_Type);
    s.attr("Float32") = py::handle((PyObject *) &PyFloat_Type);
    s.attr("Float64") = py::handle((PyObject *) &PyFloat_Type);
    s.attr("Int32")   = py::handle((PyObject *) &PyLong_Type);
    s.attr("UInt32")  = py::handle((PyObject *) &PyLong_Type);
    s.attr("Int64")   = py::handle((PyObject *) &PyLong_Type);
    s.attr("UInt64")  = py::handle((PyObject *) &PyLong_Type);

    using Float = double;

    m.def("fmadd", [](Float a, Float b, Float c) {
        return enoki::fmadd(a, b, c);
    });
    m.def("fmsub", [](Float a, Float b, Float c) {
        return enoki::fmsub(a, b, c);
    });
    m.def("fnmadd", [](Float a, Float b, Float c) {
        return enoki::fnmadd(a, b, c);
    });
    m.def("fnmsub", [](Float a, Float b, Float c) {
        return enoki::fnmsub(a, b, c);
    });

    m.def("abs",   [](Float a) { return enoki::abs(a); });
    m.def("sqr",   [](Float a) { return enoki::sqr(a); });
    m.def("sqrt",  [](Float a) { return enoki::sqrt(a); });
    m.def("cbrt",  [](Float a) { return enoki::cbrt(a); });
    m.def("rcp",   [](Float a) { return enoki::rcp(a); });
    m.def("rsqrt", [](Float a) { return enoki::rsqrt(a); });

    m.def("ceil",  [](Float a) { return enoki::ceil(a); });
    m.def("floor", [](Float a) { return enoki::floor(a); });
    m.def("round", [](Float a) { return enoki::round(a); });
    m.def("trunc", [](Float a) { return enoki::trunc(a); });

    m.def("sin",    [](Float a) { return enoki::sin(a); });
    m.def("cos",    [](Float a) { return enoki::cos(a); });
    m.def("sincos", [](Float a) { return enoki::sincos(a); });
    m.def("tan",    [](Float a) { return enoki::tan(a); });
    m.def("sec",    [](Float a) { return enoki::sec(a); });
    m.def("csc",    [](Float a) { return enoki::csc(a); });
    m.def("cot",    [](Float a) { return enoki::cot(a); });
    m.def("asin",   [](Float a) { return enoki::asin(a); });
    m.def("acos",   [](Float a) { return enoki::acos(a); });
    m.def("atan",   [](Float a) { return enoki::atan(a); });
    m.def("atan2",  [](Float a, Float b) {
        return enoki::atan2(a, b);
    });

    m.def("sinh",    [](Float a) { return enoki::sinh(a); });
    m.def("cosh",    [](Float a) { return enoki::cosh(a); });
    m.def("sincosh", [](Float a) { return enoki::sincosh(a); });
    m.def("tanh",    [](Float a) { return enoki::tanh(a); });
    m.def("sech",    [](Float a) { return enoki::sech(a); });
    m.def("csch",    [](Float a) { return enoki::csch(a); });
    m.def("coth",    [](Float a) { return enoki::coth(a); });
    m.def("asinh",   [](Float a) { return enoki::asinh(a); });
    m.def("acosh",   [](Float a) { return enoki::acosh(a); });
    m.def("atanh",   [](Float a) { return enoki::atanh(a); });

    m.def("hsum",    [](Float a) { return a; });
    m.def("hprod",   [](Float a) { return a; });
    m.def("hmin",    [](Float a) { return a; });
    m.def("hmax",    [](Float a) { return a; });

    m.def("hsum_nested",  [](Float a) { return a; });
    m.def("hprod_nested", [](Float a) { return a; });
    m.def("hmin_nested",  [](Float a) { return a; });
    m.def("hmax_nested",  [](Float a) { return a; });

    m.def("psum",    [](Float a) { return enoki::psum(a); });
    m.def("reverse", [](Float a) { return enoki::reverse(a); });

    m.def("log",    [](Float a) { return enoki::log(a); });
    m.def("exp",    [](Float a) { return enoki::exp(a); });
    m.def("erfinv", [](Float a) { return enoki::erfinv(a); });
    m.def("erf",    [](Float a) { return enoki::erf(a); });
    m.def("pow",    [](Float a, Float b) {
        return enoki::pow(a, b);
    });

    m.def("lerp", [](Float a, Float b, Float t) {
        return enoki::lerp(a, b, t);
    });
    m.def("clamp", [](Float value, Float min, Float max) {
        return enoki::clamp(value, min, max);
    });

    m.def("isfinite", [](Float a) { return enoki::isfinite(a); });
    m.def("isnan", [](Float a) { return enoki::isnan(a); });
    m.def("isinf", [](Float a) { return enoki::isinf(a); });

    m.def("tzcnt",  [](size_t a) { return enoki::tzcnt(a); });
    m.def("lzcnt",  [](size_t a) { return enoki::lzcnt(a); });
    m.def("popcnt", [](size_t a) { return enoki::popcnt(a); });
    m.def("log2i",  [](size_t a) { return enoki::log2i(a); });

    bind_scalar_0d(m, s);
    bind_scalar_1d(m, s);
    bind_scalar_2d(m, s);
    bind_scalar_3d(m, s);
    bind_scalar_4d(m, s);
    bind_scalar_complex(m, s);
    bind_scalar_matrix(m, s);
    bind_scalar_pcg32(m, s);
}