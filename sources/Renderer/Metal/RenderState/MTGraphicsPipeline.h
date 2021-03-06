/*
 * MTGraphicsPipeline.h
 * 
 * This file is part of the "LLGL" project (Copyright (c) 2015-2018 by Lukas Hermanns)
 * See "LICENSE.txt" for license information.
 */

#ifndef LLGL_MT_GRAPHICS_PIPELINE_H
#define LLGL_MT_GRAPHICS_PIPELINE_H


#import <Metal/Metal.h>

#include <LLGL/GraphicsPipeline.h>
#include <LLGL/ForwardDecls.h>
#include <cstdint>


namespace LLGL
{


class MTGraphicsPipeline : public GraphicsPipeline
{

    public:

        MTGraphicsPipeline(id<MTLDevice> device, const GraphicsPipelineDescriptor& desc);

        inline id<MTLRenderPipelineState> GetRenderPipelineState() const
        {
            return renderPipelineState_;
        }
    
        inline id<MTLDepthStencilState> GetDepthStencilState() const
        {
            return depthStencilState_;
        }
    
        inline MTLPrimitiveType GetMTLPrimitiveType() const
        {
            return primitiveType_;
        }
    
        inline std::uint32_t GetStencilRef() const
        {
            return stencilRef_;
        }

    private:

        id<MTLRenderPipelineState>  renderPipelineState_    = nil;
        id<MTLDepthStencilState>    depthStencilState_      = nil;
        MTLPrimitiveType            primitiveType_          = MTLPrimitiveTypeTriangle;
        std::uint32_t               stencilRef_             = 0;

};


} // /namespace LLGL


#endif



// ================================================================================
