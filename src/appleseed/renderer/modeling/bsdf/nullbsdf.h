
//
// This source file is part of appleseed.
// Visit http://appleseedhq.net/ for additional information and resources.
//
// This software is released under the MIT license.
//
// Copyright (c) 2010-2012 Francois Beaune, Jupiter Jazz Limited
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//

#ifndef APPLESEED_RENDERER_MODELING_BSDF_NULLBSDF_H
#define APPLESEED_RENDERER_MODELING_BSDF_NULLBSDF_H

// appleseed.renderer headers.
#include "renderer/global/global.h"
#include "renderer/modeling/bsdf/bsdf.h"

namespace renderer
{

//
// A dummy BSDF.
//

class NullBSDF
  : public BSDF
{
  public:
    NullBSDF()
      : BSDF("null_bsdf", Reflective, ParamArray())
    {
    }

    virtual void release() OVERRIDE
    {
        delete this;
    }

    virtual const char* get_model() const OVERRIDE
    {
        return "null_bsdf";
    }

    virtual Mode sample(
        SamplingContext&                sampling_context,
        const void*                     data,
        const bool                      adjoint,
        const bool                      cosine_mult,
        const foundation::Vector3d&     geometric_normal,
        const foundation::Basis3d&      shading_basis,
        const foundation::Vector3d&     outgoing,
        foundation::Vector3d&           incoming,
        Spectrum&                       value,
        double&                         probability) const OVERRIDE
    {
        return Absorption;
    }

    virtual double evaluate(
        const void*                     data,
        const bool                      adjoint,
        const bool                      cosine_mult,
        const foundation::Vector3d&     geometric_normal,
        const foundation::Basis3d&      shading_basis,
        const foundation::Vector3d&     outgoing,
        const foundation::Vector3d&     incoming,
        const int                       modes,
        Spectrum&                       value) const OVERRIDE
    {
        return 0.0;
    }

    virtual double evaluate_pdf(
        const void*                     data,
        const foundation::Vector3d&     geometric_normal,
        const foundation::Basis3d&      shading_basis,
        const foundation::Vector3d&     outgoing,
        const foundation::Vector3d&     incoming,
        const int                       modes) const OVERRIDE
    {
        return 0.0;
    }
};

}       // namespace renderer

#endif  // !APPLESEED_RENDERER_MODELING_BSDF_NULLBSDF_H
