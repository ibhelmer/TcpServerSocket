// This software is part of OpenMono, see http://developer.openmono.com
// Released under the MIT license, see LICENSE.txt

#ifndef touch_system_interface_h
#define touch_system_interface_h

#include "application_run_loop_task_interface.h"
#include "point.h"
#include "touch_responder.h"
#include "touch_event.h"
#include "consoles.h"

#include "rect.h"


#include <stdio.h>

namespace mono {

    /**
     * A calibration given for a touch system. It defines origin offsets,
     * and the scales of the mapping between screen coords and touch input
     * values.
     *
     * A calibration should enable a touch controller to accuratly translate
     * its touch into screen coords.
     */
    typedef geo::Rect TouchCalibration;

    /**
     * Interface for the Touch sub-system
     *
     *
     */
    class ITouchSystem
    {
    protected:
        
        TouchEvent lastTouchBegin;
        geo::Point lastTouchPosition;
        bool touchInProgress;
        
        /**
         * <# description #>
         *
         * @brief <# brief desc #>
         * @param <# param desc #>
         */
        void runTouchBegin(geo::Point &pos)
        {
            lastTouchBegin = TouchEvent(TouchEvent::TOUCH_BEGIN, pos, this);
            TouchResponder::RunResponderChainTouchBegin(lastTouchBegin);
        }
        
        /**
         * <# description #>
         *
         * @brief <# brief desc #>
         * @param <# param desc #>
         */
        void runTouchMove(geo::Point &pos)
        {
            TouchEvent event(TouchEvent::TOUCH_MOVE, pos, this);
            event.TouchBeginEvent = &lastTouchBegin;
            TouchResponder::RunResponderChainTouchMove(event);
        }
        
        /**
         * <# description #>
         *
         * @brief <# brief desc #>
         * @param <# param desc #>
         */
        void runTouchEnd(geo::Point &pos)
        {
            TouchEvent event(TouchEvent::TOUCH_END, pos, this);
            event.TouchBeginEvent = &lastTouchBegin;
            TouchResponder::RunResponderChainTouchEnd(event);
        }
        
    public:
        
        /**
         * <# description #>
         *
         * @brief Initialize the touch system controller
         */
        virtual void init() = 0;
        
        /**
         * <# description #>
         *
         * @brief <# brief desc #>
         */
        virtual void processTouchInput() = 0;
        
        
        virtual int ToScreenCoordsX(int touchPos, uint16_t screenWidth) = 0;
        
        
        virtual int ToScreenCoordsY(int touchPos, uint16_t screenHeight) = 0;
        
        virtual TouchCalibration CurrentCalibration() = 0;

        virtual void setCalibration(TouchCalibration &cal) = 0;
    };

}

#endif /* touch_system_interface_h */