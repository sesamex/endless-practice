import rclpy
from rclpy.node import Node
from custom_msgs.msg import NumPair

class NumPublisher(Node):
    def __init__(self):
        super().__init__('num_publisher')
        self.publisher_ = self.create_publisher(NumPair, 'num_topic', 10)
        self.timer = self.create_timer(1.0, self.timer_callback)
        self.num1 = 1.0
        self.num2 = 2.0
        self.get_logger().info('发布方节点已启动！')

    def timer_callback(self):
        msg = NumPair()
        msg.num1 = self.num1
        msg.num2 = self.num2
        self.publisher_.publish(msg)
        self.get_logger().info(f'发布 -> num1: {msg.num1}, num2: {msg.num2}')
        self.num1 += 1.0
        self.num2 += 1.0

def main(args=None):
    rclpy.init(args=args)
    node = NumPublisher()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
