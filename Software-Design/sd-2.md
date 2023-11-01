
<details>
  <summary style="font-size: 30px; font-weight: 500; cursor: pointer;">October 27th Lecture</summary>

*Natural Language Scenario*:
- Trying to get a better sense of Quality Components

*In FCAPS* they talk about Quality Attributes with N.L.

**Exam Question Hint**

Take this Description, and move it into a Quality Attribute Scenario
*(Source, Stimulus, Artifact, Environment Response, Response Measure)*


*Architecture* Is more influenced by Quality Attributes

### Utility Tree:

![ut](../static/SD_ut.png)

- 2nd Column : Seperating Q.A Attributes more specifically
- 3rd Column : (Priority, Technical Risk)
    - Priority of Q.A *(important or not)*
    - Technical Risk; can we develop this !?

**(H,H)** Is the ones you need to address first always, *High Priority, High Risk*

**Utility Tree : ASR**
Core Functionality of LMS System for EX: *Content Distribution for Students & Teachers*

*Q.A Scenario* Which gives you a bit of an insight on the *(Source, Stimulus, Artifact, Environment Response, Response Measure)*

---

**QAW** vs **Utility Tree**

- Different, but same goal "Listing and Prioritizing the most Important Quality Attributes"

---

### Integrability General Scenario:

![ut](../static/SD_ugs.png)
![ut2](../static/SD_ugs2.png)

---

**Package Diagram**
- Use Dependency 
- Can have 1 layer with many different seperations

--- 

*Hint | SD 5*:

Highlighting the Natural Language:

**Identify Different Attributes**

Quality Attribute table | Source | Stimulus | Artifcat | Response & Measure

*Modifiability*, *Interop*, etc... *Reliability*


</details>


<details>
  <summary style="font-size: 30px; font-weight: 500; cursor: pointer;">November 1st Lecture</summary>


**ADD Iteration 1:** Due Nov. 12

- Question on the Example
- Design Process that covers overview of Design


**ADD Iteration 2:**

- ???

--- 

**Layer Architecture**

- Layers seperate dependencies

## **Reference Architecture**

- Refference model, mapped onto an Architectural Pattern
- *Blueprint:* 

**WEB Reference Architecture Example**
- Distributed Client/Server Architecture

![Web Ref](../static/SD_web_ref.png)

**Presentation Layer**
- Here it's in the backend, similar to Django filling out *Template HTML* JINJA

**Web Frameworks**:
- Emphasize the Business Layer, as the Developer will be modifying this alot, for their SaaS app or wtv.


Isn't an Implementation !!!!

**Cross Cutting**
- Security *(On The business side, On the Data side)*
- Communication *(Comms across layers)*

---

**Rich Client Applications Reference Architecture**
- For example, Gaming, where the entire game is on 1 machine
- No Deployment *(Like no browser)*

![Web Ref](../static/SD_web_ref_2.png)

---

**Rich Internet Applications Reference Architecture**
- JavaScript & XML *(AJAX)*


![Web Ref](../static/SD_web_ref_3.png)

- **Plugin**: has business logic
- **Caching**: Permanency, Isolated files *(Outside the browser)* 

#### Limitations with RIA
  - Loading time is non-negligible
  - Access to local ressources can be limited


---

## Application Frameworks

- Re-usable software element to produce specific App
- Based on Patterns, Tactics
- Domain Specific *(Web, Game, Desktop App)*
- Increases productivity of Programmers *(Don't need to implement from scratch)*

**Static Web Rendering**

![Web Ref](../static/SD_web_ref_4.png)


**Dynamic Web Servers**
Like DJANGO
- Templating Language *(JINJA)*

![Web Ref 5](../static/SD_web_ref_5.png)

---

![Web Ref 6](../static/SD_web_ref_6.png)

--- 

**DJANGO**
- You don't need to deal with Cross-Cutting, WE GOT IT
- Just do the Business Logic
- Debugging is hard, as you're working at quite a High Level of Abstraction
- ORM *(Abstraction layer for DB)*

- "Batteries Included" Philosophy
- Completeness, Versatility, Security, Scalability, 
Maintainability, Portability

![Web Ref 7](../static/SD_web_ref_7.png)

- Django: VIEW for every URL
- Data Driven Framework

**Hint**: Which package does all Logic?


URLS.py

![Web Ref 8](../static/SD_web_ref_8.png)

path('catalog/') ROUTING

VIEWS.py

![Web Ref 9](../static/SD_web_ref_9.png)

**request** can be broken down, to get req. parameters
For example `/book/1` , DJANGO can decode that with `HTTPRequest` obj to have `request.id`

MODELS.py

![Web Ref 10](../static/SD_web_ref_10.png)

---

Querying from VIEWS.py

![Web Ref 11](../static/SD_web_ref_11.png)

Rendering of Data, "The template has access to a list variable called *youngest_teams* that is contained in the context
variable inside the render() function."

![Web Ref 12](../static/SD_web_ref_12.png)


**Django also includes:**

- HTML Forms: to collect data for processing on the
server.
- User authentication:
- Caching: to improve the performance of accessing the
HTML pages.
- Administration: provides admin pages to create, edit,
and view data models.
- Serializing data: can serve data as XML or JSON. Good
for creating a Web service as opposed to Web application.

---

**Web Service**
API based, Service application provides service to other Applications

**Web Applications**
Actual Web Application that serves content to Client

</details>