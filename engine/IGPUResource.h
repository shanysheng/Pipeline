/*
 * Copyright 2017 sheng chongshan. All rights reserved.
 * email: shany.sheng@qq.com
 * License: https://github.com/shanysheng/RenderPipeline/blob/master/LICENSE
 */

#ifndef PIPELINE_IGPURESOURCE_H_GUARD
#define PIPELINE_IGPURESOURCE_H_GUARD

#include "Common.h"

namespace pipeline{
    
    class IGPUResource
    {
    public:
        friend class CGPUResourceManipulator;
        IGPUResource();
        
        uint32_t	GetRefenceCount()const{return m_ReferenceCount;}
        int32_t	GetGPUMemoryCost() const{return m_GPUMemoryCost;}
        
        virtual void Bind()const{};
        virtual void Unbind()const{};
        
    protected:
        IGPUResource*	Reference(){ ++m_ReferenceCount; return this;}
        void			Unreference(){ --m_ReferenceCount;}
        virtual	~IGPUResource ();
        
    protected: 
        int32_t			m_ReferenceCount;
        uint32_t		m_GPUMemoryCost;
    };
}

#endif
