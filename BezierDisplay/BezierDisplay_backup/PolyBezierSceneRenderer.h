//
//  PolyBezierSceneRenderer.h
//  BezierDisplay
//
//  Created by Papoj Thamjaroenporn on 11/15/12.
//  Copyright (c) 2012 Papoj Thamjaroenporn. All rights reserved.
//

#ifndef __BezierDisplay__PolyBezierSceneRenderer__
#define __BezierDisplay__PolyBezierSceneRenderer__

#include "RenderingUtilities.h"
#include "PolyBezierScene.h"
#include "CurveDef.h"
#include <iostream>

class PolyBezierSceneRenderer
{
public:

	PolyBezierSceneRenderer( const PolyBezierScene & scene );
	
	void keyboard( unsigned char key, int x, int y );
	
	void setCurveColor( double r, double g, double b, double a = 1.0 );
	void setCurveColor( const renderingutils::Color & color );
	
	void setCurveHistoryColor( double r, double g, double b, double a = 1.0 );
	void setCurveHistoryColor( const renderingutils::Color & color );
	
	void setCurveHullColor( double r, double g, double b, double a = 1.0 );
	void setCurveHullColor( const renderingutils::Color & color  );

	void setCurveThickness( double t );
	void setCurveHistoryThickness( double t );
	void setCurveHullThickness( double t, double r );		// Hull Line, and Radius of ctrl points


	void setRenderCurve( bool r );
	void setRenderCurveHistory( bool r );
	void setRenderCurveHull( bool r );
	
	void renderScene() const;
	const PolyBezierScene & getScene() const;

private:
	
	void renderCurve( const VectorX2s & samplePoints ) const;
	
	// TODO: Do this.
	void renderCurveHistory() const;

	// For now, render a circle. TODO: make it size-independent; use point sprite.
	void renderCurveHull( const VectorX2s & controlPoints ) const;

//
//	void CheckForExtension(void);

private:
	
	
	
	
	const PolyBezierScene & m_curveScene;
	
	renderingutils::Color m_curveColor;
	renderingutils::Color m_curveHistoryColor;
	renderingutils::Color m_curveHullColor;
	
	double m_curveThickness;
	double m_curveHistoryThickness;
	
	double m_curveHullThickness;
	double m_controlPointRadius;
	
	bool m_renderCurve;
	bool m_renderCurveHistory;
	bool m_renderCurveHull;

//	bool m_PointARBEnable;
//	bool m_PointNVEnable;
//	PFNGLPOINTPARAMETERFARBPROC  glPointParameterfARB  ;
//	PFNGLPOINTPARAMETERFVARBPROC glPointParameterfvARB ;

};

#endif /* defined(__BezierDisplay__PolyBezierSceneRenderer__) */
