// =========================================================================================
// KXG363 - Advanced Games Programming, 2012
// =========================================================================================
//
// Author: Robert Ollington
//
// perflogtask.h
//
// Simple class to track framerates and write to file when app closes

#ifndef PERFLOGTASK_H
#define PERFLOGTASK_H

#include "Task.h"

namespace T3D{

	#define PERF_SAMPLING_PERIOD	0.15f			// calculation/update time period

	class PerfLogTask :
		public Task
	{
	public:
		PerfLogTask(T3DApplication *app);
		virtual ~PerfLogTask(void);

		virtual void update(float dt);

		bool getDiagDisplay() { return diagDisplay; };
		void setDiagDisplay(bool state) { diagDisplay = state; };

	protected:
		long int frameCount;	// total frame count
		float elapsedTime;		// total elapsed time

		float sampleElapsed;	// elapsed performance sampling period (up to PERF_SAMPLING_PERIOD)
		float sampleFrames;		// number of frames within sampling period

		// Recorded frame rates
		float avgFrameRate;
		float minFrameRate;
		float maxFrameRate;

		// Alternate way of calculating avergae frame rate
		long int sampleCount;
		float frameRateTotal;

		bool diagDisplay;		// text overlay display flag
		Texture *diagOverlay;	// last overlay texture generated

		virtual void log();
		virtual void reset();		// reset elasped time, frame count, min/max frames times
	};
}

#endif

