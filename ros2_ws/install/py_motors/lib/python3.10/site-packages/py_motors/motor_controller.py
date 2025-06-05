import rclpy
from rclpy.node import Node
from py_motors.MotorCommands import*


from custom_interfaces.msg import MotorCommand


class MotorController(Node):

    def __init__(self):
        super().__init__('motor_controller')
        self.subscription = self.create_subscription(MotorCommand, 'MotorCommand',self.listener_callback,5)

    def _match_all_motorcmds(self, motor_cmds):
        m_channel = 0
        m_state = MotorState.STOPPED
        m_speed = MotorSpeed.SLOW
        for motor_cmd in motor_cmds:
            match motor_cmd:
                case 0:
                    m_state = MotorState.STOPPED
                    m_speed = MotorSpeed.SLOW
                case 1:
                    m_state = MotorState.FORWARD
                    m_speed = MotorSpeed.SLOW
                case 2:
                    m_state = MotorState.REVERSE
                    m_speed = MotorSpeed.SLOW
                case 3:
                    m_state = MotorState.FORWARD
                    m_speed = MotorSpeed.MEDIUM
                case 4:
                    m_state = MotorState.REVERSE
                    m_speed = MotorSpeed.MEDIUM
                case 5:
                    m_state = MotorState.FORWARD
                    m_speed = MotorSpeed.FAST
                case 6:
                    m_state = MotorState.REVERSE
                    m_speed = MotorSpeed.FAST
                case _:
                    m_channel += 1
                    continue
            SetMotorState(m_state,m_speed,m_channel)
            self.get_logger().info('Published motor command (%s : %s) to motor %d' % (m_state.name, m_speed.name,m_channel))
            m_channel += 1

    def listener_callback(self, msg):
        self.get_logger().info('I heard  command %d, %d, %d, %d, %d, %d' % (msg.motor_cmds[0],
                                                                            msg.motor_cmds[1],
                                                                            msg.motor_cmds[2],
                                                                            msg.motor_cmds[3],
                                                                            msg.motor_cmds[4],
                                                                            msg.motor_cmds[5]))

        self._match_all_motorcmds(motor_cmds=msg.motor_cmds)
        
        self.get_logger().info("Motor State Set...")

                



def main(args = None):
    rclpy.init(args = args)
    motor_controller = MotorController()

    InitMotor()
    rclpy.spin(motor_controller)
    CleanupMotor()
    motor_controller.destroy_node()
    rclpy.shutdown()




if __name__ == '__main__':
    main()