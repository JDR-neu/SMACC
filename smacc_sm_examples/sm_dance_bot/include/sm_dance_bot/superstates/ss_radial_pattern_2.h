
namespace SS2
{
//forward declaration for initial ssr
class SsrRadialRotate;
class SsrRadialReturn;
class SsrRadialEndPoint;
class SsrRadialLoopStart;

struct SsRadialPattern2 : smacc::SmaccState<SsRadialPattern2, SmDanceBot, SsrRadialLoopStart>
{
public:
    using SmaccState::SmaccState;

    typedef mpl::list<

        // Expected event
        smacc::transition<EvLoopEnd<SsrRadialLoopStart>, StNavigateReverse1, ENDLOOP>//,

        // Keyboard events
        //smacc::transition<EvKeyPressN<SbKeyboard>, StNavigateReverse1>,
        //smacc::transition<EvKeyPressP<SbKeyboard>, StNavigateToWaypointsX>,

        // Error events
        //smacc::transition<smacc::EvTopicMessageTimeout<SbLidarSensor>, StAcquireSensors>,
        //smacc::transition<EvActionAborted<smacc::SmaccMoveBaseActionClient>, StNavigateToWaypointsX>
        >
        reactions;

    static void onDefinition()
    {
        //static_configure<KeyboardOrthogonal, SbKeyboard>();
        //static_configure<ObstaclePerceptionOrthogonal, SbLidarSensor>();
    }

    void onInitialize()
    {
    }

    int iteration_count = 0;
    static constexpr int total_iterations() { return 4; }
    static constexpr float ray_angle_increment_degree() { return 90; }
    static constexpr float ray_length_meters() { return 3; }
};

//forward declaration for the superstate
using SS = SsRadialPattern2;
#include <sm_dance_bot/superstate_routines/radial_motion/ssr_radial_end_point.h>
#include <sm_dance_bot/superstate_routines/radial_motion/ssr_radial_return.h>
#include <sm_dance_bot/superstate_routines/radial_motion/ssr_radial_rotate.h>
#include <sm_dance_bot/superstate_routines/radial_motion/ssr_radial_loop_start.h>
} // namespace SS2
