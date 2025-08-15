from setuptools import find_packages, setup

package_name = 'py_objectdetection'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='robocats',
    maintainer_email='johnjamisonfoth@gmail.com',
    description='TODO: Package description',
    license='Apache-2.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'detector = py_objectdetection.detection_publisher:main',
            'mapper = py_objectdetection.depth_image_to_map_o3d:main',
            'image_saver = py_objectdetection.image_stream_save:main'            
        ],
    },
)
