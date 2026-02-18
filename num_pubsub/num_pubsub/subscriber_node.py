import rclpy
from rclpy.node import Node
from custom_msgs.msg import NumPair

class NumSubscriber(Node):
    def __init__(self):
        super().__init__('num_subscriber')
        self.subscription = self.create_subscription(
            NumPair,
            'num_topic',
            self.listener_callback,
            10
        )
        self.get_logger().info('订阅方节点已启动！')

    def listener_callback(self, msg):
        result = msg.num1 + msg.num2
        self.get_logger().info(
            f'收到 -> num1: {msg.num1}, num2: {msg.num2}, num1 + num2 = {result}'
        )

def main(args=None):
    rclpy.init(args=args)
    node = NumSubscriber()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
