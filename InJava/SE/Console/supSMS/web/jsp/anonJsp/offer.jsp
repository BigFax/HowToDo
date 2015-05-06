<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@page contentType="text/html" pageEncoding="UTF-8"%>

<%@ include file="/header.jsp"%>

<c:url value="/anon/register" var="registerUrl" />
<h1 id="page_title">Offer page</h1>

<div class="main_sep"></div>

<h3 class="l-center">The offer</h3>
<div class="sentence">
    <strong>SupSMS</strong>, the SMS service that people trust !<br>
    Our service is the best WEB SERVICE for enterprises or individuals for only <strong>10$ Monthly</strong> !<br>
    Available 7/11, our service never crash and allow you a strong solution for everybody.
</div>
<div class="subscribe">  
    <a href="${registerUrl}" class="btn btn-primary-custom" role="button">SUBSCRIBE NOW</a>
</div>

<div class="sep"></div>

<div>
    <h3 class="l-center">What our customers say</h3>
    <ul>
        <li>
            <blockquote>
                <div>" SupSMS has the best solution we need to send/receive sms from all our paltform. This is THE tool that all people was waiting for ! "</div>
                <em>-- Giorgio Moroder, Full professor at Midnight Express School.</em>
            </blockquote>
        </li>
    </ul>
</div>
<div style="clear: both;"></div>
<div class="l-center" style="margin: 15px 0 0 0;">
    <a href="#" style="font-weight: bold;">Read all testimonials</a>
</div>

<div class="sep"></div>

<div>
    <h3 class="l-center">They love our job</h3>
    <ul class="logos">
        <li>
            <img alt="Activision" src="/supSMS/img/activision.png">
        </li>
        <li>
            <img alt="Sony" src="/supSMS/img/sony.png">
        </li>
        <li>
            <img alt="jQuery" src="/supSMS/img/jquery.png">
        </li>
        <li>
            <img alt="Ford" src="/supSMS/img/ford.png">
        </li>
        <li>
            <img alt="Nissan" src="/supSMS/img/nissan.png">
        </li>
        <li>
            <img alt="npr" src="/supSMS/img/npr.png">
        </li>
        <li>
            <img alt="Ralph Lauren" src="/supSMS/img/ralph-lauren.png">
        </li>
        <li>
            <img alt="Tetra Pak" src="/supSMS/img/tetra.png">
        </li>
    </ul>
</div>

<%@ include file="/footer.jsp"%>