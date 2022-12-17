# 3081W Homework4 - Project
#### Group Number:
Team-001-47

#### Members:
- Luna Kim (kim01289)
- Ethan Loukusa (louku008)

###	What is the project about 
> We implemented a human-friendly system by utilizing behavioral simulations of drones and robots. Our project idea is to extend drone simulation by adding human and ATM entities. We also proceed under the assumption that human entities first go to nearby ATMs to use automotive entities. You will be able to set the departure point and final destination, and the car will come to pick you up after you withdraw money from the nearest ATM. You then created a traffic simulation to arrive at the desired location with the shortest route.

### Run the Simulation
Here is a quick overview of how to run the visualization (If you are using ssh, navigate to ssh category below):

    ```bash
    # Go to the project directory
    cd /path/to/repo/project
    
    # Build the project
    make -j
    
    # Run the project (./build/web-app <port> <web folder>)
    ./build/bin/transit_service 8081 apps/transit_service/web/
    ```
    
Navigate to http://127.0.0.1:8081 and you should see a visualization.

Navigate to http://127.0.0.1:8081/schedule.html and you should see a page to schedule the trips.

Below are instructions that detail how to build and run in several different environments.  

## Getting Started using SSH onto CSE Lab machines

1. SSH into a CSE Lab Machine using **port forwarding** for the UI

   **Note:** If port `8081` is not available, choose a different port (e.g. 8082, 8083, etc...)

    ```bash
    ssh -L 8081:127.0.0.1:8081 x500@csel-xxxx.cselabs.umn.edu
    ```
    
    Example:
    ```bash
    ssh -L 8081:127.0.0.1:8081 kaung006@csel-kh1250-05.cselabs.umn.edu
    ```

2. Compile the project (within ssh session)

    ```bash
    cd /path/to/repo/project
    make -j
    ```
    
 2. Run project (within ssh session)

    ```bash
    ./build/bin/transit_service 8081 apps/transit_service/web/
    ```

5. Navigate to http://127.0.0.1:8081 and you should see a visualization.

6. Navigate to http://127.0.0.1:8081/schedule.html and you should see a page to schedule the trips.

# Simulation

## Schedule
You will be able to schedule the robots for a ride in this page http://127.0.0.1:8081/schedule.html. 

Type passenger name, select start and end destination, and press `Schedule Trip` button to schedule a trip. 

Now go to 3D Visualization page and select the view of the entities(ATM or Car) on top right corner.

## 3D Visualization
You will be able to watch the simulation of the drone and the passenger here http://127.0.0.1:8081.

On top right corner, you can change your camera view into locking the entities.


### What does the simulation do?
>The simulation spawns five ATM devices on the map. You can set the departure where you are now and arrival points through http://127.0.0.1:8081/schedule.html. If you set up a schedule, you will arrive at the ATM closest to you because you are currently short of money and cannot use your car. If you withdraw money from an ATM, you will call a car. The car picks you up and travels through the shortest route to the point of arrival.

### New Feature, what does it do? Why is it significatly interesting?
>We think the new features are groundbreaking ideas that can be applied to the real world. We set up an ATM in the middle of the car picking up person, so that when the arrival reached the desired point, the car could be picked up. However, we think it is a simulation that can be used in various ways if ATM is changed to other uses. If a child reaches kindergarten, it can automatically recognize the GPS and it can send a car on time to go home. Also, when you go on a trip, when you arrive at the airport at the destination, you can automatically add the function of calling Uber to the airport. It is a simple simulator like this, but I think its utilization is endless.

### How does it add to the existing work?
First, we added cars, people, and ATM entities. After downloading the glb and converting the robot entity into a person and the drone entity into a car, the glb was inserted and spawned on the map.
Next, Atm.cc, AtmFactory.cc, Atm.h, and AtmFacotry.h were written. Five Atm were spawn to the proper place as the car was added(lab10) to um.json.
Finally, Person reaches the nearest Atm, we implemented Car.cc and Person.cc to make Car to pick up the person and go to the set destination thorugh nearest route.


### Which design pattern did you choose to implement it and why?
- Factory : The factory pattern defines an interface for creating an object, but lets the subclasses decide which class to instantiate. Factory method lets a class defer instantiation to subclasses. This pattern should be used when the number of items to generate will rarely change in your software development. For example, in our simulation if we were only going to generate drones, packages, and customers then the concrete factory should be used. Since we are not limiting ourselves to these entities, the concrete factory should not be used.
- Decorator : When Car Etity and Person Entity arrived at their destination, they tried to realize celebration by spinning or running around. For this, we used a decorator pattern. Celebration Decorator class, Spin Decorator class, and Jump Decorator class were used.

### Instruction to use this new feature
It's the same with `Run the Simulation` until #4 but the different thing is a visualization.

5. Navigate to http://127.0.0.1:8081 and you should see a visualization.

6. Navigate to http://127.0.0.1:8081/schedule.html and you should see a page to schedule the trips.

7. You can set the trip that you start to move right now and the destination you want to go.

# Simulation

## Schedule
You will be able to schedule the robots for a ride in this page http://127.0.0.1:8081/schedule.html. 

Type passenger name, select start and end destination, and press `Schedule Trip` button to schedule a trip. 

Now go to 3D Visualization page and select the view of the entities(ATM or Car) on top right corner.

## 3D Visualization
You will be able to watch the simulation of the car, ATM and person here http://127.0.0.1:8081.

On top right corner, you can change your camera view into locking the entities.


### sprint retrospective
What we first planned was more specific and detailed. A person has a certain amount of money and it is shown on the map. The car calculates the money according to the distance we go, informs us, and we only use ATMs when we are short of money. The reason why this is difficult to implement is that the value of using the car varies depending on the location of the ATM. For example, we now have $8. The price of using the car in its current location is $10 but it could be $7 if it reaches the ATM to withdraw money. The design to represent our budget was also a challenge. What started with imagination seemed simple, but there were so many steps to implement it as a real program. 
We changed the plan a little bit more simply, and we planned a simulation that we could use the car when we eventually reached the desired location. This simulation was never easy either. So far, in the lab, we learned how to add a vehicle, but it took a lot of time to create another entity, ATM. Also, with the addition of ATM entities, we had to transform many existing drone entities and robot entities. The change in glb and the creation of people, cars, and ATMs went smoothly. As a result, the simulation was successfully completed. In addition, as we mention above, if specific charges are set, the simulation will be improved more conveniently. Also, if there is anything to be desired, the decorator was not properly implemented because of the glb. Since it is a Decorator written according to a robot, it is not implemented in a car glb.


## 1 UML
#####UML Diagram
![UML Diagram](https://github.umn.edu/Ethan-Loukusa/Team001-047-Homework4/UML.png)

## 2 Docker
> Link : `https://docs.google.com/document/d/1uXb0h3z5HqZoSFgCbT-PnQ88jzXXg7fuhY_taZSSDkA/edit`

## 3 Video Presentation
> Link : `https://docs.google.com/presentation/d/1VHok0wf1aL1ONPQEfRAl8ZVFYZeHnFBgQPqbYZNIPtw/edit#slide=id.gc6f80d1ff_0_5`(add video on the slide)